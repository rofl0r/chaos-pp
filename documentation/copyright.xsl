<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="html" doctype-public="-//W3C//DTD HTML 4.0 Strict//EN" indent="yes" encoding="UTF-8"/>

<xsl:template name="copyright">
	<xsl:param name="author"/>
	<xsl:param name="date"/>
	<xsl:if test="string-length($author) = 0">
		<xsl:message terminate="yes">error: no author specified for copyright</xsl:message>
	</xsl:if>
	<xsl:if test="string-length($date) = 0">
		<xsl:message terminate="yes">error: no date specified for copyright</xsl:message>
	</xsl:if>
	<xsl:variable name="address">
		<xsl:choose>
			<xsl:when test="$author = 'Paul Mensonides'">pmenso57@users.sourceforge.net</xsl:when>
		</xsl:choose>
	</xsl:variable>
	<HR/>
	<ADDRESS>
		<xsl:choose>
			<xsl:when test="$address = ''">
				© Copyright <xsl:value-of select="concat($author, ' ')"/><xsl:value-of select="$date"/>.
			</xsl:when>
			<xsl:otherwise>
				© Copyright <A href="mailto:{$address}"><xsl:value-of select="concat($author, ' ')"/></A><xsl:value-of select="$date"/>.
			</xsl:otherwise>
		</xsl:choose>
	</ADDRESS>
	<ADDRESS>
		Use, modification, and distribution of this document are subject to the <A href="http://www.boost.org">Boost Software License, Version 1.0</A>.
		See <A href="http://chaos-pp.sourceforge.net">http://chaos-pp.sourceforge.net</A> for the most recent version of this document.
	</ADDRESS>
</xsl:template>

</xsl:stylesheet>
