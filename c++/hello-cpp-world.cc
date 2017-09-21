#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <sstream>
using namespace std;
const string proArr []= {"HOPOPT",
  "ICMP",
  "IGMP",
  "GGP",
  "IPv4",
  "ST",
  "TCP",
  "CBT",
  "EGP",
  "IGP",
  "BBN-RCC-MON",
  "NVP-II",
  "PUP",
  "ARGUS",
  "EMCON",
  "XNET",
  "CHAOS",
  "UDP",
  "MUX",
  "DCN-MEAS",
  "HMP",
  "PRM"  ,
  "XNS-IDP",
  "TRUNK-1",
  "TRUNK-2",
  "LEAF-1",
  "LEAF-2",
  "RDP",
  "IRTP",
  "ISO-TP4",
  "NETBLT",
  "MFE-NSP",
  "MERIT-INP",
  "DCCP",
  "3PC",
  "IDPR",
  "XTP",
  "DDP",
  "IDPR-CMTP",
  "TP++",
  "IL",
  "IPv6",
  "SDRP",
  "IPv6-Route",
  "IPv6-Frag",
  "IDRP",
  "RSVP",
  "GRE",
  "DSR",
  "BNA",
  "ESP",
  "AH",
  "I-NLSP",
  "SWIPE",
  "NARP",
  "MOBILE",
  "TLSP",
  "SKIP",
  "IPv6-ICMP",
  "IPv6-NoNxt",
  "IPv6-Opts",
  "any host internal",
  "CFTP",
  "any local network",
  "SAT-EXPAK",
  "KRYPTOLAN",
  "RVD",
  "IPPC",
  "any distribute file",
  "SAT-MON",
  "VISA",
  "IPCV",
  "CPNX",
  "CPHB",
  "WSN",
  "PVP",
  "BR-SAT-MON",
  "SUN-ND",
  "WB-MON",
  "WB-EXPAK",
  "ISO-IP",
  "VMTP",
  "SECURE-VMTP",
  "VINES",
  "TTP,IPTM",
  "NSFNET-IGP",
  "DGP",
  "TCF",
  "EIGRP",
  "OSPFIGP",
  "Sprite-RPC",
  "LARP",
  "MTP",
  "AX.25",
  "IPIP",
  "MICP",
  "SCC-SP ",
  "ETHERIP",
  "ENCAP ",
  "any private enc schema",
  "GMTP",
  "IFMP",
  "PNNI",
  "PIM ",
  "ARIS",
  "SCPS",
  "QNX ",
  "A/N",
  "IPComp",
  "SNP",
  "Compaq-Peer",
  "IPX-in-IP",
  "VRRP",
  "PGM",
  "any 0-hop",
  "L2TP",
  "DDX",
  "IATP",
  "STP",
  "SRP",
  "UTI",
  "SMP",
  "SM (deprecated)",
  "PTP",
  "ISIS over IPv4 ",
  "FIRE",
  "CRTP",
  "CRUDP",
  "SSCOPMCE",
  "IPLT",
  "SPS",
  "PIPE",
  "SCTP",
  "FC",
  "RSVP-E2E-IGNORE",
  "Mobility Header",
  "UDPLite",
  "MPLS-in-IP",
  "manet",
  "HIP",
  "Shim6",
  "WESP",
  "ROHC",
  "unassigned"
};

void seq(){
    ifstream ifs;
    ifs.open("extSeq");
    string item;
     ofstream ofs;
     ofs.open("seq.txt");
    while(!ifs.eof()){
        getline(ifs,item);
        
        if(item.size() ==1){
            item = "0";
        }
        //cout << item << endl;
        ofs<<item<<endl;

    }
    ofs.close();
    
}

vector<vector<string>> vectorProcess(){
    ifstream ifs;
    ifstream seqIfs;
    string dump;
    string item;
    //seq();
    vector<string> sourceIp;
    vector<string> destIp;
    vector<string> protocol;
    vector<string> sourcePort;
    vector<string> destPort;
    vector<string> timestamp;
    vector<string> psize;
    vector<string> flags;
    vector<string> seqNum;
    vector<vector<string>> allcont;
    ifs.open("../IO/output");
    //seqIfs.open("seq.txt");
    while(ifs.good()){
      
        ifs >>item;
        sourceIp.push_back(item);
         ifs >>item;
        destIp.push_back(item);
         ifs >>item;
        protocol.push_back(item);
         ifs >>item;
        sourcePort.push_back(item);
         ifs >>item;
        destPort.push_back(item);
         ifs >>item;
        timestamp.push_back(item);
         ifs >>item;
        psize.push_back(item);
         ifs >>item;
        flags.push_back(item);
    
       
    }
    
    // while(seqIfs.good()){
    //     seqIfs>>item;
    //     seqNum.push_back(item);
        
    // }
    allcont.push_back(sourceIp);
    allcont.push_back(destIp);
    allcont.push_back(protocol);
    allcont.push_back(sourcePort);
    allcont.push_back(destPort);
    allcont.push_back(timestamp);
    allcont.push_back(psize);
    allcont.push_back(flags);
    //allcont.push_back(seqNum);
    ifs.close();
    //seqIfs.close();
    return allcont;
}


void getHeatMap(vector<vector<string>>& allcont){
        ofstream ofs;
        ofs.open("srcIpVsDestIpVsSize.txt");
        vector<string> sourceIp = allcont[0];
        vector<string> destIp = allcont[1];
        vector<string> psize = allcont[6];
        for(int i = 0; i<sourceIp.size()-1; i++){
            ofs<<sourceIp[i];
            ofs<<"\t";
            ofs<<destIp[i];
            ofs<<"\t";
            ofs<<psize[i];
            ofs<<"\n";
           
        }
    
       
        ofs.close();
    }
    
void getFrequencySize(vector<vector<string>>& allcont){
    vector<string> psize = allcont[6];
    unordered_map<string, int> freqeuncy;
    
    for(int i = 0; i<psize.size()-1; i++){
        if (freqeuncy.count(psize[i])){
            freqeuncy[psize[i]] +=1;
          
        }
        else if (!freqeuncy.count(psize[i])){
            freqeuncy[psize[i]] =1;
       
        }
        
    }
   
      ofstream ofs;
     ofs.open("../networkAnalysis/json/sizeFreq.json");
     ofs<<"[{\"x\":[";
      for ( auto it = freqeuncy.begin(); it != freqeuncy.end(); ++it ){
     
    
      ofs<< "\""<<it->first<<"\"";
      auto jt = it;
      if(++jt!=freqeuncy.end()){
          ofs<<",";
      }
      }
    ofs<<"], \"y\":[";
    for ( auto it = freqeuncy.begin(); it != freqeuncy.end(); ++it ){
      ofs<< "\""<<it->second<<"\"";
      auto jt = it;
      if(++jt!=freqeuncy.end()){
          ofs<<",";
      }
      }
    
    ofs<<"],  \"type\" : \"bar\"}]";
    ofs.close();
    
      
      
      
    
}


void getFrequencyProtocol(vector<vector<string>>& allcont){
    vector<string> protocol = allcont[2];
    unordered_map<string, int> freqeuncy;
    
    for(int i = 0; i<protocol.size()-1; i++){
        if (freqeuncy.count(protocol[i])){
            freqeuncy[protocol[i]] +=1;
          
        }
        else if (!freqeuncy.count(protocol[i])){
            freqeuncy[protocol[i]] =1;
       
        }
        
    }
   
     ofstream ofs;
     ofs.open("../networkAnalysis/json/freqVsProtocol.json");
     ofs<<"[{\"x\":[";
      for ( auto it = freqeuncy.begin(); it != freqeuncy.end(); ++it ){
      //cout << " " << it->first << ":" << it->second<< endl;
        int i = stol(it->first);
        if(i>142){
            i = 143;
        }
      //ofs<<proArr[i]<< "\t" << it->second<<endl;
      ofs<< "\""<<proArr[i]<<"\"";
      auto jt = it;
      if(++jt!=freqeuncy.end()){
          ofs<<",";
      }
      }
    ofs<<"], \"y\":[";
    for ( auto it = freqeuncy.begin(); it != freqeuncy.end(); ++it ){
      //cout << " " << it->first << ":" << it->second<< endl;
        int i = stol(it->first);
        if(i>142){
            i = 143;
        }
      //ofs<<proArr[i]<< "\t" << it->second<<endl;
      ofs<< "\""<<it->second<<"\"";
      auto jt = it;
      if(++jt!=freqeuncy.end()){
          ofs<<",";
      }
      }
    
    ofs<<"],  \"type\" : \"bar\"}]";
    ofs.close();
    
      
      
      
      ofs.close();
    
}


string DecimalToBinaryString(int dec)
{

    char bin6[]  = "000000";
    for (int pos = 5; pos >= 0; --pos)
    {
        if (dec % 2) 
            bin6[pos] = '1';
        dec /= 2;
    }
    string result;//string which will contain the result
    stringstream convert;
    
  for (int temp = 0; temp <6; temp++){
 
    
    convert<<bin6[temp];
    result = convert.str();
    
  }
  
  return result;
}

void getResetVsTime(vector<vector<string>>& allcont){
    vector<string> flags = allcont[7];
    vector<string> timestamp = allcont[5];
    unordered_map<string, int> freqeuncy;
    string bin; 
    string rst;
    ofstream ofs;
     ofs.open("../networkAnalysis/json/rstVsTime.json");
     int sum=0;
     double diff = 0.1;
     double ntime = 0;
    for(int i = 0; i<timestamp.size()-1; i++){
        bin = DecimalToBinaryString(stol(flags[i]));
        rst = bin[3];
        ntime = stod(timestamp[i]);
        int j = ++i;
        if(rst == "1"){
            if(diff - ntime <0){
                freqeuncy[timestamp[i]] = sum;
                diff += 0.1;
                sum = 0;
                }
            }
            else{
                sum+=1;
            }
            
            
            
        }
        ofs<<"[{\"x\":[";
        for ( auto it = freqeuncy.begin(); it != freqeuncy.end(); ++it ){
            ofs<<"\""<<it->first<<"\"";
            auto jt = it;
            if (++jt != freqeuncy.end()){
                ofs<<",";
            }
        }
    
        
    
    ofs<<"],"<<"\""<<"y"<<"\""<<":[";
    for ( auto it = freqeuncy.begin(); it != freqeuncy.end(); ++it ){
            ofs<<"\""<<it->second<<"\"";
            auto jt = it;
            if (++jt != freqeuncy.end()){
                ofs<<",";
            }
        }
    ofs<<"],  \"type\" : \"bar\"}]";
    ofs.close();
}


void getICMPOthers(vector<vector<string>>& allcont){
    vector<string> protocol = allcont[2];
    unordered_map<string, int> freqeuncy;
    
    for(int i = 0; i<protocol.size()-1; i++){
        if (freqeuncy.count(protocol[i])){
            freqeuncy[protocol[i]] +=1;
          
        }
        else if (!freqeuncy.count(protocol[i])){
            freqeuncy[protocol[i]] =1;
       
        }
        
    }
   
     ofstream ofs;
     ofs.open("../networkAnalysis/json/ICMPOthers.json");
     if(!ofs){
         cout<<"error"<<endl;
     }
     int sum = 0;
     int j=0;
      for ( auto it = freqeuncy.begin(); it != freqeuncy.end(); ++it ){
      //cout << " " << it->first << ":" << it->second<< endl;
        int i = stol(it->first);
        j = it->second;
        if(i>142){
            i = 143;
        }
        if(i == 1){
            
        }
        else{
            sum+= j;
        }
      
      }
      //ofs<<"others"<< "\t" << sum<<endl;
      //ofs<<proArr[1]<<"\t" << freqeuncy["1"]<<endl;
      
    
    ofs<<"[{\"labels\":[";
    ofs<< "\""<<proArr[1]<<"\""<<", "<<"\""<<"others"<<"\"";
    ofs<<"], \"values\":[";
    ofs<<freqeuncy["1"]<<","<<sum;
    ofs<<"],  \"type\" : \"pie\"}]";
    ofs.close();
    
    
}


void getSynVsTime(vector<vector<string>>& allcont){
    vector<string> flags = allcont[7];
    vector<string> timestamp = allcont[5];
    unordered_map<string, int> freqeuncy;
    string bin; 
    string rst;
    ofstream ofs;
     ofs.open("../networkAnalysis/json/synVsTime.json");
     int sum=0;
     double diff = 0.1;
     double ntime = 0;
    for(int i = 0; i<timestamp.size()-1; i++){
        bin = DecimalToBinaryString(stol(flags[i]));
        rst = bin[4];
        ntime = stod(timestamp[i]);
        int j = ++i;
        if(rst == "1"){
            if(diff - ntime <0){
                freqeuncy[timestamp[i]] = sum;
                diff += 0.1;
                sum = 0;
                }
            }
            else{
                sum+=1;
            }
            
            
            
        }
        ofs<<"[{\"x\":[";
        for ( auto it = freqeuncy.begin(); it != freqeuncy.end(); ++it ){
            ofs<<"\""<<it->first<<"\"";
            auto jt = it;
            if (++jt != freqeuncy.end()){
                ofs<<",";
            }
        }
    
        
    
    ofs<<"],"<<"\""<<"y"<<"\""<<":[";
    for ( auto it = freqeuncy.begin(); it != freqeuncy.end(); ++it ){
            ofs<<"\""<<it->second<<"\"";
            auto jt = it;
            if (++jt != freqeuncy.end()){
                ofs<<",";
            }
        }
    ofs<<"],  \"type\" : \"bar\"}]";
    ofs.close();
}

void getFinVsTime(vector<vector<string>>& allcont){
    vector<string> flags = allcont[7];
    vector<string> timestamp = allcont[5];
    unordered_map<string, int> freqeuncy;
    string bin; 
    string rst;
    ofstream ofs;
     ofs.open("../networkAnalysis/json/FinVsTime.json");
     int sum=0;
     double diff = 0.1;
     double ntime = 0;
    for(int i = 0; i<timestamp.size()-1; i++){
        bin = DecimalToBinaryString(stoi(flags[i]));
        rst = bin[5];
        ntime = stod(timestamp[i]);
        int j = ++i;
        if(rst == "1"){
            if(diff - ntime <0){
                freqeuncy[timestamp[i]] = sum;
                diff += 0.1;
                sum = 0;
                }
            }
            else{
                sum+=1;
            }
            
            
            
        }
        ofs<<"[{\"x\":[";
        for ( auto it = freqeuncy.begin(); it != freqeuncy.end(); ++it ){
            ofs<<"\""<<it->first<<"\"";
            auto jt = it;
            if (++jt != freqeuncy.end()){
                ofs<<",";
            }
        }
    
        
    
    ofs<<"],"<<"\""<<"y"<<"\""<<":[";
    for ( auto it = freqeuncy.begin(); it != freqeuncy.end(); ++it ){
            ofs<<"\""<<it->second<<"\"";
            auto jt = it;
            if (++jt != freqeuncy.end()){
                ofs<<",";
            }
        }
    ofs<<"],  \"type\" : \"bar\"}]";
    ofs.close();
}





int main() {
    vector<vector<string>>  allcont;
    allcont = vectorProcess();
 
     getFrequencySize(allcont);
     getFrequencyProtocol(allcont);
     getICMPOthers(allcont);
     getResetVsTime(allcont);
     getFinVsTime(allcont);
     getSynVsTime(allcont);
    
}
    
