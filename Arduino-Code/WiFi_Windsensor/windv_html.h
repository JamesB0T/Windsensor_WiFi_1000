// Wind values webpage
String Windv()
{
 // Debug info 
 DebugPrintln(3, "Send windv.html");

 // Page content with JavaScript and JSON for updating
 String content;
 content +=F( "<!DOCTYPE html>");
 content +=F( "<html>");
 content +=F( "<head>");
 content +=F( "<title>Windsensor Values</title>");
 content +=F( "<link rel='stylesheet' type='text/css' href='/css'>");
 content +=F( "<meta http-equiv='content-type' content='text/html; charset=UTF-8'>");
 content +=F( "<meta name=viewport content='width=device-width, initial-scale=1'>");

 // Special local format
 content +=F( "<style>");
 content +=F( "</style>");
 content +=F( "</head>");
 content +=F( "<body>");
 
 content +=F( "<script>");
 content +=F( "var xmlhttp = new XMLHttpRequest();");
 content +=F( "xmlhttp.onreadystatechange = function() {");
 content +=F( "if (this.readyState == 4 && this.status == 200) {");
 content +=F( "var myObj = JSON.parse(this.responseText);");

 content +=F( "var winddir = 0;");
 content +=F( "var dirunit = '  ';");
 content +=F( "winddir = myObj.Device.MeasuringValues.WindDirection.Value;");
 content +=F( "winddir = Math.round(winddir*10)/10;");
 content +=F( "dirunit = myObj.Device.MeasuringValues.WindDirection.Unit;");
 content +=F( "var dir = winddir + ' ' + dirunit;");
 content +=F( "document.getElementById('winddir').innerHTML = dir;");

 content +=F( "var windspeed = 0;");
 content +=F( "var speedunit = '  ';");
 content +=F( "windspeed = myObj.Device.MeasuringValues.WindSpeed.Value;");
 content +=F( "windspeed = Math.round(windspeed*10)/10;");
 content +=F( "speedunit = myObj.Device.MeasuringValues.WindSpeed.Unit;");
 content +=F( "var speed = windspeed + ' ' + speedunit;");
 content +=F( "document.getElementById('windspeed').innerHTML = speed;");
 
 content +=F( "document.getElementById('quality').innerHTML = myObj.Device.NetworkParameter.ConnectionQuality.Value;");
// content +=F( "document.getElementById('winddir').innerHTML = myObj.Device.MeasuringValues.WindDirection.Value;");
// content +=F( "document.getElementById('dirunit').innerHTML = myObj.Device.MeasuringValues.WindDirection.Unit;");
// content +=F( "document.getElementById('windspeed').innerHTML = myObj.Device.MeasuringValues.WindSpeed.Value;");
// content +=F( "document.getElementById('speedunit').innerHTML = myObj.Device.MeasuringValues.WindSpeed.Unit;");

 // If Demo Mode active the give out a message
 content += F("servermode = myObj.Device.NetworkParameter.ServerMode;");
 content += F("if (servermode == 4) {");
 content += F("document.getElementById('info').innerHTML = '(Demo Mode)';");
 content += F("}");
 content += F("else {");
 content += F("document.getElementById('info').innerHTML = '';");
 content += F("}");

 content +=F( "}");
 content +=F( "};");
 content +=F( "function read_json() {");
// content +=F( "xmlhttp.open('GET', 'http://192.168.4.1/json', true);");
 content +=F( "xmlhttp.open('GET', '/json', true);");
 content +=F( "xmlhttp.send();");
 content +=F( "}");
 content +=F( "setInterval(function(){read_json(); }, 1000);");
 content +=F( " </script>");
 
 // Web page title
 content +=F( "<h2>");
 content += String(actconf.devname);
 content +=F( "</h2>");
 content += String(actconf.crights);
 content +=F( ", "); 
 content += String(actconf.fversion);
 content +=F( ", CQ: <data id = 'quality'></data>%");
 content +=F( "<hr align='left'>");
 
 content +=F( "<h3>Windsensor Values  <blink><data id='info'></data></blink></h3>");
 
 content +=F( "<FONT SIZE='7'>");
 
 content +=F( "<table>");
 
 content +=F( "<tr>");
 content +=F( "<td></td>");
 content +=F( "<td><data id='winddir'></data></td>");
 content +=F( "<td><data id='dirunit'></data></td>");
 content +=F( "</tr>");

 content +=F( "<tr>");
 content +=F( "<td></td>");
 content +=F( "<td><data id='windspeed'></data></td>");
 content +=F( "<td><data id='speedunit'></data></td>");
 content +=F( "</tr>");

 content +=F( "</table>");

 content +=F( "</FONT>");
 
 content +=F( "<br>");
 content +=F( "<hr align='left'>");
 content +=F( "<br>");
 content +=F( "<form action='/'><button type='submit'>Back</button></form>");
 content +=F( "</body>");
 content +=F( "</html>");

 return content;
}
