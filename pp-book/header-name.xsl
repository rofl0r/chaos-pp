<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<!-- <xsl:param name="library"/> -->

<xsl:template name="header-name">
	<xsl:param name="header-name"/>
	<xsl:variable name="header-name-format" select="document($library)/library/@header-name-format"/>
	<xsl:choose>
		<xsl:when test="$header-name-format = 'h-char-sequence'">&lt;<xsl:value-of select="$header-name"/>&gt;</xsl:when>
		<xsl:when test="$header-name-format = 'q-char-sequence'">"<xsl:value-of select="$header-name"/>"</xsl:when>
	</xsl:choose>
</xsl:template>

</xsl:stylesheet>
