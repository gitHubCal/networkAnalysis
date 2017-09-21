function loadJSON(file, callback) {   
    var xobj = new XMLHttpRequest();
    xobj.overrideMimeType("application/json");
    xobj.open('GET', file, true); // Replace 'my_data' with the path to your file
    xobj.onreadystatechange = function () {
          if (xobj.readyState == 4 && xobj.status == "200") {
            // Required use of an anonymous callback as .open will NOT return a value but simply returns undefined in asynchronous mode
            callback(xobj.responseText);
          }
    };
    xobj.send(null);  
 };

//X-Y Charts
function returnLayout(title, x_axis_title, x_axis_type, y_axis_title, y_axis_type, hovermode) {
    var layout = {
        title: title,
        xaxis: {
        title: x_axis_title,
        type: x_axis_type
        },
        yaxis: {
        title: y_axis_title,
        type: y_axis_type
        },
        hovermode: hovermode
    };
    return layout;
}

//Pie Charts
function returnLayout2(title) {
    var layout = {
        title: title,
    };
    return layout;
}

function load(jsonFile,divID,layout) {
    loadJSON(jsonFile, function(response) {
        var actual_JSON = JSON.parse(response);
        console.log(actual_JSON);
        Plotly.newPlot(divID, actual_JSON,layout);
    })
};

$(document).click(function(e) {
    var $notClick = $(e.target);
    var $nav = $(".navbar-collapse");               
    var $nav_opened = $nav.hasClass("in");
    if ($nav_opened === true && $notClick.hasClass("navbar-toggle") === false) {      
        $nav.collapse('hide');
    }
});