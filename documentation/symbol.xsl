<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:o=".">

<xsl:output method="xml" indent="yes" encoding="UTF-8"/>
<xsl:namespace-alias stylesheet-prefix="o" result-prefix="xsl"/>

<xsl:param name="prefix"/>

<xsl:template match="/library">
	<o:stylesheet version="1.0">
		<xsl:for-each select="macro">
			<o:template match="{@id}" name="{@id}">
				<CODE><A class="{@type}" href="{{$root}}/{substring-before(@header, '.')}.html#{@id}"><xsl:value-of select="concat($prefix, @id)"/></A></CODE>
			</o:template>
		</xsl:for-each>
		<xsl:for-each select="header">
			<o:template match="{translate(@name, '/', '-')}">
				<CODE><A class="header" href="{{$root}}/{substring-before(@name, '.')}.html">&lt;<xsl:value-of select="@name"/>&gt;</A></CODE>
			</o:template>
		</xsl:for-each>
	</o:stylesheet>
</xsl:template>

</xsl:stylesheet>
