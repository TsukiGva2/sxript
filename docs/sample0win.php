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
    <h3><b>Navgation</h3>
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
    <a href="../../index.html#Home">[Home]</a> -
    <a href="../console/console.html#Top">[Console]</a> -
    <a href="../../index.html#Guide">[Guide]</a> -
    <a href="../../index.html#Applications">[Applications]</a> -
    <a href="../../index.html#Index">[Index]</a> -
    <a href="javascript:history.back()">[Back]</a>
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
