<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="xml" indent="yes" encoding="UTF-8"/>

<xsl:template match="/library">
	<library name="@name">
		<xsl:apply-templates>
			<xsl:with-param name="path" select="@name"/>
		</xsl:apply-templates>
	</library>
</xsl:template>

<xsl:template match="/library//directory">
	<xsl:param name="path"/>
	<xsl:apply-templates>
		<xsl:with-param name="path" select="concat($path, '/', @name)"/>
	</xsl:apply-templates>
</xsl:template>

<xsl:template match="/library//header">
	<xsl:param name="path"/>
	<header name="{$path}/{@name}"/>
	<xsl:apply-templates select="document(concat($path, '/', substring-before(@name, '.'), '.xml'))/header/macro">
		<xsl:with-param name="path" select="concat($path, '/', @name)"/>
	</xsl:apply-templates>
</xsl:template>

<xsl:template match="/header/macro | /header/macro//derivative">
	<xsl:param name="path"/>
	<xsl:param name="type" select="'primary'"/>
	<macro id="{@id}" header="{$path}" type="{$type}"><xsl:call-template name="make-groups"/></macro>
	<xsl:apply-templates select="derivative">
		<xsl:with-param name="path" select="$path"/>
		<xsl:with-param name="type" select="'derivative'"/>
	</xsl:apply-templates>
</xsl:template>

<xsl:template name="make-groups">
	<xsl:param name="string" select="string(@group)"/>
	<xsl:choose>
		<xsl:when test="contains($string, ' ')">
			<group id="{substring-before($string, ' ')}"/>
			<xsl:call-template name="make-groups">
				<xsl:with-param name="string" select="substring-after($string, ' ')"/>
			</xsl:call-template>
		</xsl:when>
		<xsl:when test="string-length($string)">
			<group id="{$string}"/>
		</xsl:when>
	</xsl:choose>
</xsl:template>

</xsl:stylesheet>
