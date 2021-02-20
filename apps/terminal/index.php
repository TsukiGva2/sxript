<html>
<head>

<title>Terminal</title>

<link rel="icon" href="../../src/sxript.ico">
<script type="text/javascript" src="../../web-js/jquery-1.11.3.js"></script>
<script type="text/javascript" src="../../src/sxript.js"></script>
<script type="text/javascript" src="../../src/qbf.js"></script>
<script>

$(document).ready(function() {
  $("#textin").keyup(function (e) {
    if ((e.keyCode == 13)) {

    var theinput;
    var thecleaninput;
    theinput = $("#textin").val();
    thecleaninput = cleanup(theinput);
    document.mainform.areatext.value = "\n: " + thecleaninput + "\n" + document.mainform.areatext.value;
    document.mainform.areatext.value = "\n: " + process(thecleaninput) + document.mainform.areatext.value;

    document.getElementById("textin").value = thecleaninput;
    document.getElementById("textin").select();
    document.getElementById("textin").focus();
    }
  });
});

function cleanup (txtin) {
    return txtin.replace(/(\r\n|\n|\r)/gm, "");
}

function process (txtin) {
    return sxriptEval(txtin);
}

</script>

<link rel="stylesheet" href="../../web-css/styles-main.css">
<link rel="stylesheet" href="../../web-css/styles-terminal.css">

</head>
 
<body>

<form name="inputform">
<textarea id="textin" class="inputbar" rows="1">
</textarea>
</form>

<form name="mainform">
<textarea id="areatext" class="console" readonly rows="16">
</textarea>
</form>

<?php $pathtoroot = "../../"; ?>
<?php include($_SERVER['DOCUMENT_ROOT']."/sxript/web-php/header.php"); ?>

<script>
document.getElementById("textin").focus();

(function () {
  "use strict";
  document.mainform.areatext.value = "\n";
  document.mainform.areatext.value += "*** Welcome to Sxript ***" + "\n";
  document.mainform.areatext.value += "   (JavaScript Build)" + "\n";
  document.mainform.areatext.value += "\n";
}());
</script>

</body>
</html>
