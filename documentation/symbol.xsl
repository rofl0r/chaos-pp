<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:xso=".">

<xsl:output method="xml" indent="yes" encoding="UTF-8"/>
<xsl:namespace-alias stylesheet-prefix="xso" result-prefix="xsl"/>

<xsl:template match="/library">
	<xso:stylesheet version="1.0">
		<xsl:for-each select="macro">
			<xso:template match="{@id}" name="{@id}">
				<CODE><A class="{@type}" href="{{$root}}/{substring-before(@header, '.')}.html#{@id}">CHAOS_PP_<xsl:value-of select="@id"/></A></CODE>
			</xso:template>
		</xsl:for-each>
		<xsl:for-each select="header">
			<xso:template match="{translate(@name, '/', '-')}">
				<CODE><A class="header" href="{{$root}}/{substring-before(@name, '.')}.html">&lt;<xsl:value-of select="@name"/>&gt;</A></CODE>
			</xso:template>
		</xsl:for-each>
	</xso:stylesheet>
</xsl:template>

</xsl:stylesheet>
