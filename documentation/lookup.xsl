<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="html" doctype-public="-//W3C//DTD HTML 4.0 Strict//EN" indent="yes" encoding="UTF-8"/>

<!-- manual symbol lookup -->

<xsl:template name="manual">
	<xsl:param name="id" select="@id"/>
	<xsl:choose>
		<xsl:when test="contains($id, '.')">
			<xsl:variable name="nodeset" select="document('.library.xml')/library/header[@name = $id]"/>
			<xsl:choose>
				<xsl:when test="count($nodeset)">
					<CODE><A class="header" href="{$root}/{substring-before($nodeset[1]/@name, '.')}.html">&lt;<xsl:value-of select="$id"/>&gt;</A></CODE>
				</xsl:when>
				<xsl:otherwise>
					<xsl:call-template name="unknown-entity">
						<xsl:with-param name="text">&lt;<xsl:value-of select="$id"/>&gt;</xsl:with-param>
					</xsl:call-template>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:when>
		<xsl:otherwise>
			<xsl:variable name="nodeset" select="document('.library.xml')/library/macro[@id = $id]"/>
			<xsl:choose>
				<xsl:when test="count($nodeset)">
					<CODE><A class="{$nodeset[1]/@type}" href="{$root}/{substring-before($nodeset[1]/@header, '.')}.html#{$id}">CHAOS_PP_<xsl:value-of select="$id"/></A></CODE>
				</xsl:when>
				<xsl:otherwise>
					<xsl:call-template name="unknown-entity">
						<xsl:with-param name="text">CHAOS_PP_<xsl:value-of select="$id"/></xsl:with-param>
					</xsl:call-template>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

<xsl:template name="manual-parent">
	<xsl:param name="id" select="../@id"/>
	<xsl:call-template name="manual">
		<xsl:with-param name="id" select="$id"/>
	</xsl:call-template>
</xsl:template>

</xsl:stylesheet>
