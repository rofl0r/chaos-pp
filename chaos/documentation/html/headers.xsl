<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="html" indent="yes" encoding="UTF-8"/>

<xsl:template match="/lookup">
	<html>
		<head>
			<title>Chaos - Header Index</title>
			<link rel="stylesheet" type="text/css" href="style.css"/>
			<body>
				<h4>Headers</h4>
				<ul>
					<xsl:for-each select="header">
						<li><a href="reference/{@src}.html"><code>&lt;chaos/preprocessor/<xsl:value-of select="@src"/>.hpp&gt;</code></a></li>
					</xsl:for-each>
				</ul>
			</body>
		</head>
	</html>
</xsl:template>

</xsl:stylesheet>
