<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>
<head><title>menu</title>
</head>
<body>
<h2>Burgers creators</h2>
<table border="1">
<tr bgcolor="#9acd32">
<th>burgers</th>
<th>creator</th>
<th>year</th>
</tr>
<xsl:for-each select="menu/element">
<xsl:sort select="year" order="ascending"/>
<tr>
<td><xsl:value-of select="burger"/></td>
<td><xsl:value-of select="creator"/></td>
<td><xsl:value-of select="year"/></td>
</tr>
</xsl:for-each>
</table>
</body>
</html>
</xsl:template>
</xsl:stylesheet>