<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/">
    <html>
      <head>
        <title>menu</title>
      </head>
      <body>
        <h2>Attestation</h2>
        <table border="1">
          <tr bgcolor="#9acd32">
            <th>#</th>
            <th>Name</th>
            <th>Mark</th>
          </tr>
          <xsl:for-each select="exams/person">
            <xsl:sort select="order" order="ascending"/>
            <tr>
              <td bgcolor="aqua"><xsl:value-of select="order"/></td>
              <td><xsl:value-of select="name"/></td>
              <xsl:choose>
                  <xsl:when test="mark &lt; 4">
                    <td bgcolor="red"><xsl:value-of select="mark"/></td>
                  </xsl:when>
                  <xsl:when test="mark &gt; 8">
                    <td bgcolor="green"><xsl:value-of select="mark"/></td>
                  </xsl:when>
                  <xsl:otherwise>
                    <td bgcolor="white"><xsl:value-of select="mark"/></td>
                  </xsl:otherwise>
                </xsl:choose>
            </tr>
          </xsl:for-each>
        </table>
      </body>
    </html>
  </xsl:template>
</xsl:stylesheet>
