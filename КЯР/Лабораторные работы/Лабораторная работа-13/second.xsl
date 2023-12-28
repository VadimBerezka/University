<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
            <body bgcolor="#aaa">
                <h1>Аттестация студентов</h1>
                <table border="5" bgcolor="#aaa">
                    <tr bgcolor="lightblue">
                        <th>Специальность</th>
                        <th>Фамилия</th>
                        <th>Имя</th>
                        <th>Группа</th>
                        <th>Оценка</th>
                    </tr>

                    <xsl:for-each select="students/student">
                        <tr>
                            <td><xsl:value-of select="spec"/></td>                     
                            <td><xsl:value-of select="lastname"/></td>
                            <td><xsl:value-of select="firstname"/></td>
                            <td><xsl:value-of select="grup"/></td>
                            <td>
                                <xsl:attribute name="style">
                                    <xsl:choose>
                                        <xsl:when test="mark &lt; 4">background-color:red;</xsl:when>
                                        <xsl:when test="mark &gt; 8">background-color:green;</xsl:when>
                                    </xsl:choose>
                                </xsl:attribute>
                                <xsl:value-of select="mark"/>
                            </td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>