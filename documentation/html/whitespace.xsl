<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="html" doctype-public="-//W3C//DTD HTML 4.0 Strict//EN" indent="yes" encoding="UTF-8"/>

<xsl:template match="text()">
	<xsl:variable name="before" select="preceding-sibling::node()"/>
	<xsl:variable name="after" select="following-sibling::node()"/>
	<xsl:variable name="current" select="."/>
	<xsl:variable name="sans-leading-lf">
		<xsl:choose>
			<xsl:when test="count($before) = 0">
				<xsl:call-template name="remove-leading-lf">
					<xsl:with-param name="str" select="$current"/>
				</xsl:call-template>
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="$current"/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:variable>
	<xsl:choose>
		<xsl:when test="count($after) = 0">
			<xsl:call-template name="remove-trailing-ws">
				<xsl:with-param name="str" select="$sans-leading-lf"/>
			</xsl:call-template>
		</xsl:when>
		<xsl:otherwise>
			<xsl:value-of select="$sans-leading-lf"/>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

<xsl:template name="remove-leading-lf">
	<xsl:param name="str"/>
	<xsl:choose>
		<xsl:when test="starts-with($str,'&#xA;') or starts-with($str,'&#xD;')">
			<xsl:call-template name="remove-leading-lf">
				<xsl:with-param name="str" select="substring($str, 2)"/>
			</xsl:call-template>
		</xsl:when>
		<xsl:otherwise>
			<xsl:value-of select="$str"/>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

<xsl:template name="remove-trailing-ws">
	<xsl:param name="str"/>
	<xsl:variable name="last-char">
		<xsl:value-of select="substring($str, string-length($str), 1)"/>
	</xsl:variable>
	<xsl:choose>
		<xsl:when test="($last-char = '&#xA;') or ($last-char = '&#xD;') or ($last-char = '&#x20;') or ($last-char = '&#x9;')">
			<xsl:call-template name="remove-trailing-ws">
				<xsl:with-param name="str" select="substring($str, 1, string-length($str) - 1)"/>
			</xsl:call-template>
		</xsl:when>
		<xsl:otherwise>
			<xsl:value-of select="$str"/>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

</xsl:stylesheet>
