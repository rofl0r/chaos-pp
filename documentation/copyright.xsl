<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="html" doctype-public="-//W3C//DTD HTML 4.0 Strict//EN" indent="yes" encoding="UTF-8"/>

<xsl:param name="url"/>

<xsl:template name="copyright">
	<xsl:param name="author"/>
	<xsl:param name="date"/>
	<xsl:variable name="address">
		<xsl:choose>
			<xsl:when test="$author = 'Paul Mensonides'">
				<A href="mailto:pmenso57@users.sourceforge.net">Paul Mensonides</A>
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="$author"/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:variable>
	<HR/>
	<ADDRESS>
		© Copyright <xsl:copy-of select="$address"/><xsl:value-of select="' '"/><xsl:value-of select="$date"/>
	</ADDRESS>
	<ADDRESS>
		Distributed under the <A href="http://www.boost.org">Boost Software License, Version 1.0</A>.
		See <A href="{$url}"><xsl:value-of select="$url"/></A> for the most recent version of this document.
	</ADDRESS>
</xsl:template>

</xsl:stylesheet>
