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

<br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>

</body>
</html>
