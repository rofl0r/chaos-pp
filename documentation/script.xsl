<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="text" encoding="UTF-8"/>

<xsl:template match="/library">
	@echo off
	mkdir %1\<xsl:value-of select="@name"/> 2&gt; nul
	<xsl:apply-templates>
		<xsl:with-param name="path" select="@name"/>
	</xsl:apply-templates>
</xsl:template>

<xsl:template match="directory">
	<xsl:param name="path"/>
	<xsl:variable name="new-path" select="concat($path, '\', @name)"/>
	mkdir %1\<xsl:value-of select="$new-path"/> 2&gt; nul
	<xsl:apply-templates>
		<xsl:with-param name="path" select="$new-path"/>
	</xsl:apply-templates>
</xsl:template>

<xsl:template match="header">
	<xsl:param name="path"/>
	<xsl:variable name="enabled" select="'*'"/>
	<xsl:if test="true() or contains(translate(concat($path, '/', @name), '\', '/'), $enabled)">
		<xsl:variable name="sans" select="concat($path, '\', substring-before(@name, '.'))"/>
		echo <xsl:value-of select="$sans"/>.html
		msxsl <xsl:value-of select="$sans"/>.xml header.xsl -o %1\<xsl:value-of select="$sans"/>.html
		<xsl:if test="count(assoc)">
			mkdir %1\<xsl:value-of select="$sans"/> 2&gt; nul
			<xsl:for-each select="assoc">
				copy <xsl:value-of select="concat($sans, '\', @id)"/> %1\<xsl:value-of select="concat($sans, '\', @id)"/> 2&gt; nul
			</xsl:for-each>
		</xsl:if>
	</xsl:if>
</xsl:template>

</xsl:stylesheet>
