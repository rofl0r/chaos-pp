<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:o=".">

<xsl:output method="xml" indent="yes" encoding="UTF-8"/>
<xsl:namespace-alias stylesheet-prefix="o" result-prefix="xsl"/>

<xsl:template match="/register">
	<o:stylesheet version="1.0">
		<xsl:apply-templates select="document/item"/>
		<o:template match="link" priority="-1">
			<o:message terminate="yes">
				error: reference to unknown symbol "<o:value-of select="@id"/>"
			</o:message>
		</o:template>
	</o:stylesheet>
</xsl:template>

<xsl:template match="/register/document/item">
	<o:template match="link[@id = '{@value}']">
		<A href="{{$root}}/{../@id}.html"><xsl:value-of select="@value"/></A>
	</o:template>
</xsl:template>

</xsl:stylesheet>
