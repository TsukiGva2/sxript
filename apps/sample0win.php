<html>

<head>
    
<title><?php echo $headline ?></title>

<link rel="icon" href="../../src/sxript.ico">
<script type="text/javascript" src="../../src/qbf.js"></script>
<script type="text/javascript" src="../../src/sxript.js"></script>
<script type="text/javascript" src="../../web-js/jquery-1.11.3.js"></script>
<script type="text/javascript" src="../../web-js/evalbutton.js"></script>
<link href="../../web-css/styles-main.css" rel="stylesheet" type="text/css" />
<link href="../../web-css/styles-console.css" rel="stylesheet" type="text/css" />

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
<table width="100%" border="0">
    <tbody>
    <tr>
    <td>
    <center>
    <h1><?php echo $headline ?></h1>
    </center>
    </td>
    </tr>
    </tbody>
</table>
</center>

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
<table width="100%" border="0">
    <tbody>
    <tr>
    <td>
    <table width="100%" border="0">
        <tbody>
        <tr>
        <td align="right">
        </td>
        </tr>
        </tbody>
    </table>
    </td>
    </tr>
    </tbody>
</table>
</center>

<center>
<table width="97%" border="0">
    <tbody>
    <tr>
    <td>
<?php
echo file_get_contents('description.txt');
?>
    </td>
    </tr>
    </tbody>
</table>
</center>

<br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>

</body>
</html>
