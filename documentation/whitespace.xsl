<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="listing/text() | snippet/text()">
	<xsl:variable name="preceding" select="preceding-sibling::node()"/>
	<xsl:variable name="following" select="following-sibling::node()"/>
	<xsl:variable name="current" select="translate(., '&#x9;', '')"/>
	<xsl:variable name="sans-leading-lf">
		<xsl:choose>
			<xsl:when test="count($preceding) = 0">
				<xsl:call-template name="remove-leading-lf">
					<xsl:with-param name="text" select="$current"/>
				</xsl:call-template>
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="$current"/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:variable>
	<xsl:choose>
		<xsl:when test="count($following) = 0">
			<xsl:call-template name="remove-trailing-ws">
				<xsl:with-param name="text" select="$sans-leading-lf"/>
			</xsl:call-template>
		</xsl:when>
		<xsl:otherwise>
			<xsl:value-of select="$sans-leading-lf"/>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

<xsl:template name="remove-leading-lf">
	<xsl:param name="text"/>
	<xsl:choose>
		<xsl:when test="starts-with($text, '&#xA;') or starts-with($text, '&#xD;')">
			<xsl:call-template name="remove-leading-lf">
				<xsl:with-param name="text" select="substring($text, 2)"/>
			</xsl:call-template>
		</xsl:when>
		<xsl:otherwise>
			<xsl:value-of select="$text"/>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

<xsl:template name="remove-trailing-ws">
	<xsl:param name="text"/>
	<xsl:variable name="last-char">
		<xsl:value-of select="substring($text, string-length($text), 1)"/>
	</xsl:variable>
	<xsl:choose>
		<xsl:when test="($last-char = '&#xA;') or ($last-char = '&#xD;') or ($last-char = '&#x20;') or ($last-char = '&#x9;')">
			<xsl:call-template name="remove-trailing-ws">
				<xsl:with-param name="text" select="substring($text, 1, string-length($text) - 1)"/>
			</xsl:call-template>
		</xsl:when>
		<xsl:otherwise>
			<xsl:value-of select="$text"/>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

</xsl:stylesheet>
