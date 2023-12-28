<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>

<head>
<title>Games 2023</title>
</head>

<body bgcolor="#aaa">

<h1>Games 2023</h1>

<table border="5">
<tr bgcolor="#aaa">
<th>names</th>
<th>cost</th>
<th>year</th>
</tr>

<xsl:for-each select="main/game">
<xsl:sort select="year"/>

<tr bgcolor="#aaa">
<td><xsl:value-of select="name"/></td>
<td><xsl:value-of select="cost"/></td>
<td><xsl:value-of select="year"/></td>
</tr>

</xsl:for-each>
</table>
</body>

</html>
</xsl:template>
</xsl:stylesheet>