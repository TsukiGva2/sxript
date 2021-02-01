<html>

<head>
    
<title><?php echo $headline ?></title>

<script type="text/javascript" src="../../src/qbf.js"></script>
<script type="text/javascript" src="../../src/sxript.js"></script>
<script type="text/javascript" src="../jquery-1.11.3.js"></script>
<script type="text/javascript" src="../evalbutton.js"></script>

<link href="../sxriptstyles.css" rel="stylesheet" type="text/css" />

</head>
 
<body bgcolor="#CCCCCC">

<a name="Top"></a>

<center>
<table width="100%" border="0">
    <tbody>
    <tr>
    <td>
    <font face="Arial" color="#003399" size="4"><b>Navgation</b></font>
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
    <a href="../../index.html#Home" style="text-decoration:none"><font face="Courier New"; color="Black"> [Home] </font></a>
    <a href="../console/console.html#Top" style="text-decoration:none"><font face="Courier New"; color="Black"> [Console] </font></a>
    <a href="../../index.html#Guide" style="text-decoration:none"><font face="Courier New"; color="Black"> [Guide] </font></a>
    <a href="../../index.html#Applications" style="text-decoration:none"><font face="Courier New"; color="Black"> [Applications] </font></a>
    <a href="../../index.html#Index" style="text-decoration:none"><font face="Courier New"; color="Black"> [Index] </font></a>
    <a href="javascript:history.back()" style="text-decoration:none"><font face="Courier New"; color="Black"> [Back] </font></a>
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
    <center>
    <font face="Courier New" color="#003399" size="6"><?php echo $headline ?></font>
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

<br/>

<center>
<table border="1">
    <tbody>
    <tr>
    <td>
    <center>
    <table border="0">
        <tbody>
        <tr>    
        <td>
	<center>
        <font face="Courier New"><b><?php echo $name ?>.txt</b></font>
	</center>
<textarea readonly class="light" cols="80" rows="15">
<?php
echo file_get_contents('../../test/' . $name . '.txt');
?>
</textarea>
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

<br/>

<center>
<table border="1">
    <tbody>
    <tr>
    <td>
    <center>
    <table border="0">
        <tbody>
        <tr> 
        <td>
	<center>
        <font face="Courier New"><b>Test Window</b></font>
	</center>
<textarea id="sxriptin" class="console" cols="80" rows="15">
<?php
echo file_get_contents('../../test/' . $name . '-test.txt');
?>
</textarea>
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

<br/>

<center>
<button id="evalbutton" class="stylebutton" onclick="evalbutton.focus()"><b>Evaluate</b></button>
</center>

<br/>

<form name="formsxript">
<center>
<table border="1">
    <tbody>
    <tr>
    <td>
    <center>
    <table border="0">
        <tbody>
        <tr> 
        <td>
	<center>
        <font face="Courier New"><b>Output Window</b></font>
	</center>
        <center> 
<textarea id="sxriptout" class="console" cols="80" rows="15">
</textarea>
        </center>
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
</form>

<br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>

<center>
<table width="100" border="0">
    <tbody>
    <tr>
    <td>
    <hr/>
    </td>
    </tr>
    </tbody>
</table>
</center>

</body>
</html>
