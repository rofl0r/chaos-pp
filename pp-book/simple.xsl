<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="html" doctype-public="-//W3C//DTD HTML 4.0 Strict//EN" indent="yes" encoding="UTF-8"/>

<!-- <xsl:variable name="root"/> -->

<xsl:template match="code | em | sub | sup | var">
	<xsl:element name="{name()}">
		<xsl:apply-templates/>
	</xsl:element>
</xsl:template>

<xsl:template match="x-var">
	<VAR class="EXTERNAL"><xsl:apply-templates/></VAR>
</xsl:template>

<xsl:template match="assoc">
	<A href="{@id}"><xsl:apply-templates/></A>
</xsl:template>

<xsl:template match="library-assoc">
	<A href="{$root}/{@id}"><xsl:apply-templates/></A>
</xsl:template>

</xsl:stylesheet>
