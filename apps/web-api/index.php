<?php
if(isset($_GET["i"])) {
  $theinput = $_GET["i"];
} else {
  $theinput = "";
}

?>
<html>
<head>
<title>Sxript Web API</title>
<link rel="icon" href="../../src/sxript.ico">
<script type="text/javascript"></script>
<script type="text/javascript" src="../../web-js/jquery-1.11.3.js"></script>
<script type="text/javascript" src="../../src/sxript.js"></script>
<script type="text/javascript" src="../../src/qbf.js"></script>
</head>
<?php
if ($theinput !== "") {
  $tmpx = $theinput;
  echo "<body><script type=\"text/javascript\">window.document.write(sxriptEval(\"" . $tmpx . "\"))</script></body>";
} else {
  echo "<body>No input.</body>";
}
?>

</html>