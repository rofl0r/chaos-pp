<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="html" indent="yes" encoding="UTF-8"/>

<xsl:template match="/lookup">
	<html>
		<head>
			<title>Chaos - Macro Index</title>
			<link rel="stylesheet" type="text/css" href="style.css"/>
		</head>
		<body>
			<h4>Macros</h4>
			<ul>
				<xsl:for-each select="header/symbol">
					<xsl:sort select="@id"/>
					<li><a href="reference/{../@src}.html#{@id}"><code>CHAOS_PP_<xsl:value-of select="@id"/></code></a></li>
				</xsl:for-each>
			</ul>
		</body>
	</html>
</xsl:template>

</xsl:stylesheet>
