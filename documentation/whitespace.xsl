<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="listing/text() | snippet/text()">
	<xsl:variable name="sans-tabs" select="translate(., '&#x9;', '')"/>
	<xsl:variable name="sans-leading-newlines">
		<xsl:choose>
			<xsl:when test="count(preceding-sibling::node())">
				<xsl:value-of select="$sans-tabs"/>
			</xsl:when>
			<xsl:otherwise>
				<xsl:call-template name="remove-leading-newlines">
					<xsl:with-param name="text" select="$sans-tabs"/>
				</xsl:call-template>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:variable>
	<xsl:choose>
		<xsl:when test="count(following-sibling::node())">
			<xsl:value-of select="$sans-leading-newlines"/>
		</xsl:when>
		<xsl:otherwise>
			<xsl:call-template name="remove-trailing-whitespace">
				<xsl:with-param name="text" select="$sans-leading-newlines"/>
			</xsl:call-template>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

<xsl:template name="remove-leading-newlines">
	<xsl:param name="text"/>
	<xsl:choose>
		<xsl:when test="starts-with($text, '&#xA;') or starts-with($text, '&#xD;')">
			<xsl:call-template name="remove-leading-newlines">
				<xsl:with-param name="text" select="substring($text, 2)"/>
			</xsl:call-template>
		</xsl:when>
		<xsl:otherwise>
			<xsl:value-of select="$text"/>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

<xsl:template name="remove-trailing-whitespace">
	<xsl:param name="text"/>
	<xsl:variable name="last-char">
		<xsl:value-of select="substring($text, string-length($text), 1)"/>
	</xsl:variable>
	<xsl:choose>
		<xsl:when test="($last-char = '&#xA;') or ($last-char = '&#xD;') or ($last-char = '&#x20;') or ($last-char = '&#x9;')">
			<xsl:call-template name="remove-trailing-whitespace">
				<xsl:with-param name="text" select="substring($text, 1, string-length($text) - 1)"/>
			</xsl:call-template>
		</xsl:when>
		<xsl:otherwise>
			<xsl:value-of select="$text"/>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

</xsl:stylesheet>
