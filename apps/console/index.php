<html>

<head>

<title>Sxript Console</title>

<link rel="icon" href="../../src/sxript.ico">
<script type="text/javascript" src="../../web-js/jquery-1.11.3.js"></script>
<script type="text/javascript" src="../../src/sxript.js"></script>
<script type="text/javascript" src="../../src/qbf.js"></script>
<script>

$(document).ready(function() {
  $("#evalbutton").click(function() {
    var theinput;
    var thecleaninput;
    var theprocessedinput;
    theinput = $("#textin").val();
    thecleaninput = theinput.replace(/^\s+|\s+$/g, "");
    theprocessedinput = thecleaninput;

    if (document.getElementById("subprogram").checked) {
      theprocessedinput = "sub({" + theprocessedinput + "})";
    }
    if (document.getElementById("codeblock").checked) {
      theprocessedinput = "block({" + theprocessedinput + "})";
    }
	if (document.getElementById("showinput").checked) {
      document.mainform.areatext.value += "\n: " + theprocessedinput;
    }
	
    if (document.getElementById("whiteinput").checked) {
      document.mainform.areatext.value += "\n" + ": " + manageWhiteSpace(theprocessedinput) + "\n";
    } else {
      document.mainform.areatext.value += "\n" + ": " + sxriptEval(theprocessedinput) + "\n";
    }

    document.mainform.areatext.scrollTop = document.mainform.areatext.scrollHeight;
    document.getElementById("textin").value = thecleaninput;
  });
});

$(document).ready(function() {
  $("#evalbutton2").click(function() {
    var theinput;
    var thecleaninput;
    var theprocessedinput;
    theinput = $("#textin2").val();
    thecleaninput = theinput.replace(/^\s+|\s+$/g, "");
    theprocessedinput = thecleaninput;
    document.mainform.areatext.value += "\n: " + theprocessedinput + "\n";
    document.mainform.areatext.value += ": " + sxriptEval(theprocessedinput) + "\n";
    document.mainform.areatext.scrollTop = document.mainform.areatext.scrollHeight;
    document.getElementById("textin2").value = thecleaninput;
  });
});

$(document).ready(function() {
  $("#textin").keyup(function (e) {
    if ((e.keyCode == 13)) {
      if (document.getElementById("oneline").checked) {
        $("#evalbutton").click();
        document.getElementById("textin").select();
      }
    }
  });
});

$(document).ready(function() {
  $("#textin2").keyup(function (e) {
    if ((e.keyCode == 13)) {
      $("#evalbutton2").click();
      document.getElementById("textin2").select();
    }
  });
});

</script>

<!--link href="../mainstyles.css" rel="stylesheet" type="text/css" /-->
<link rel="stylesheet" href="../../web-css/styles-main.css">
<link rel="stylesheet" href="../../web-css/styles-console.css">

<style type='text/css'>
form {
  margin-top: 0px;
  margin-bottom: 0px;
  margin-right: 0px;
  margin-left: 0px;
}
</style>

</head>
 
<body>

<a name="Top"></a>

<h3>Navgation</h3>

<?php $pathtoroot = "../../"; ?>

<div class="indented">
  <?php include($_SERVER['DOCUMENT_ROOT']."/sxript/web-php/header.php"); ?>
</div>

<center>
<table width="100%" border="0">
    <tbody>
    <tr>
    <td>
    <hr/>
    </td>
    </tr>
    </tbody>
</table>
</center>

<center>
<table width="1024">
  <tbody>
  <tr>
    <td align="right" width="40%"><font color="White" size="7" face="Courier New"><b>Sxript</b></font>
    </td>
    <td align="center" width="20%"><a href="../../" target="_parent"><img src="../../img/sxlogoinv.png" alt=""/></a>
    </td>
    <td align="left" width="40%"><font color="White" size="7" face="Courier New"><b>Console</b></font>
    </td>
  </tr>
  </tbody>
</table>
</center>

<center><table width="1024"><tbody><tr><td><hr/></td></tr></tbody></table></center>

<center>
<table border="0" width="1024">
  <tbody>
  <tr valign="top">
    <td width="50%">
      <center>
<textarea id="textin" class="console" rows="27" cols="60">
</textarea>
      </center>
    </td>
    <td>
      <center> 
<form name="mainform">
<textarea id="areatext" class="console" readonly rows="27" cols="60">
</textarea>
</form>
      </center>
    </td>
  </tr>

  <tr valign="center">
    <td width="50%">
    
	<table border="0" width="100%">
      <tbody>
		<tr>
		  <td width="33%">
		    <font face="Courier New" size="3" color="#FFFFFF">[<input type="radio" style="vertical-align: middle" name="runmodes" id="oneline"/><label for="oneline"> Single Line</label>]</font>
			<br/>
			<font face="Courier New" size="3" color="#FFFFFF">[<input type="radio" style="vertical-align: middle" name="runmodes" id="subprogram"/><label for="subprogram"> Sub</label>]</font>
			<br/>
			<font face="Courier New" size="3" color="#FFFFFF">[<input type="radio" style="vertical-align: middle" name="runmodes" id="codeblock"/><label for="codeblock"> Block</label>]</font>
		  </td>
		  <td align="center">
		    <button id="evalbutton" class="stylebutton" onclick="evalbutton.focus()"><b>Evaluate</b></button>
		  </td>
		  <td>
		    <font face="Courier New" size="3" color="#FFFFFF">[<input type="radio" style="vertical-align: middle" name="printmodes" id="showinput"/><label for="showinput"> Show Input</label>]</font>
			</br>
			<font face="Courier New" size="3" color="#FFFFFF">[<input type="radio" style="vertical-align: middle" name="printmodes" id="hideinput"/><label for="hideinput"> Hide Input</label>]</font>
			<br/>
			<font face="Courier New" size="3" color="#FFFFFF">[<input type="radio" style="vertical-align: middle" name="printmodes" id="whiteinput"/><label for="hideinput"> Whitespace</label>]</font>
		  </td>
		</tr>
		<tr>
		</tbody>
	</table>

    </td>
    <td>

      <center>
      <table border="0" width="100%">
        <tbody>
        <tr>
          <td align="right">
<textarea id="textin2" class="console" rows="2" cols="60">
</textarea>
          </td>
        </tr>
        <tr>
          <td align="right">
            <button id="evalbutton2" class="stylebutton2" onclick=""><b>Immediate</b></button>
          </td>
        </tr>
        </tbody>
      </table>
      </center>
    </td>
  </tr>
  </tbody>
</table>
</center>

<center><table width="1024"><tbody><tr><td><hr/></td></tr></tbody></table></center>

<br/>

<script>
document.getElementById("oneline").checked = false;
document.getElementById("subprogram").checked = true;
document.getElementById("codeblock").checked = false;

document.getElementById("showinput").checked = true;
document.getElementById("hideinput").checked = false;

var text_input = document.getElementById("textin2");
text_input.focus();

(function () {
  "use strict";
  var z;
  document.mainform.areatext.value = "";
  for (z = 1; z <= SxriptLogoSize; z += 1) {
   document.mainform.areatext.value += SxriptLogoText[z] + "\n";
  }
  document.mainform.areatext.value += "*** Welcome to Sxript ***" + "\n";
  document.mainform.areatext.value += "   (JavaScript Build)" + "\n";
  document.mainform.areatext.value += "\n";
}());
</script>

</body>
</html>
