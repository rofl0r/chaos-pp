<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="html" doctype-public="-//W3C//DTD HTML 4.0 Strict//EN" indent="yes" encoding="UTF-8"/>

<!-- <xsl:param name="library"/> -->
<!-- <xsl:variable name="root"/> -->

<xsl:template name="get-address">
	<xsl:param name="name"/>
	<xsl:choose>
		<xsl:when test="$name = 'Paul Mensonides'">
			<A href="mailto:pmenso57@users.sourceforge.net">Paul Mensonides</A>
		</xsl:when>
		<xsl:when test="$name = 'Vesa Karvonen'">
			<A href="mailto:vesa_karvonen@users.sourceforge.net">Vesa Karvonen</A>
		</xsl:when>
		<xsl:otherwise>
			<xsl:value-of select="$name"/>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

<xsl:template name="copyright">
	<xsl:param name="author" select="/*/@author"/>
	<xsl:param name="date" select="/*/@date"/>
	<HR/>
	<ADDRESS>
		© Copyright <xsl:call-template name="get-address"><xsl:with-param name="name" select="$author"/></xsl:call-template><xsl:value-of select="concat(' ', $date)"/>.
	</ADDRESS>
	<xsl:if test="/*/secondary-author">
		<ADDRESS>
			<xsl:for-each select="/*/secondary-author">
				<xsl:sort select="@name"/>
				© Copyright <xsl:call-template name="get-address"><xsl:with-param name="name" select="@name"/></xsl:call-template><xsl:value-of select="concat(' ', @date)"/>.
			</xsl:for-each>
		</ADDRESS>
	</xsl:if>
	<ADDRESS>
		Distributed under the <A href="{$root}/license.html">Boost Software License, Version 1.0</A>.
		See <A href="{document($library)/library/@url}"><xsl:value-of select="document($library)/library/@url"/></A> for the most recent version of this document.
	</ADDRESS>
</xsl:template>

</xsl:stylesheet>
