<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="html" doctype-public="-//W3C//DTD HTML 4.0 Strict//EN" indent="yes" encoding="UTF-8"/>
<xsl:variable name="root" select="'.'"/>
<xsl:include href="common.xsl"/>

<xsl:template match="/lookup">
	<html>
		<head>
			<title>Chaos Preprocessor Library - Macro Index</title>
			<link rel="stylesheet" type="text/css" href="style.css"/>
		</head>
		<body>
			<h4>Macros</h4>
			<ul>
				<xsl:for-each select="header/macro">
					<xsl:sort select="@id"/>
					<li><code><a href="reference/{../@src}.html#{@id}">CHAOS_PP_<xsl:value-of select="@id"/></a></code></li>
				</xsl:for-each>
			</ul>
			<xsl:call-template name="copyright"/>
		</body>
	</html>
</xsl:template>

</xsl:stylesheet>
