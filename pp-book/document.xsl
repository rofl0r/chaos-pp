<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="html" doctype-public="-//W3C//DTD HTML 4.0 Strict//EN" indent="yes" encoding="UTF-8"/>

<xsl:include href=".symbol.xsl"/>

<xsl:include href="copyright.xsl"/>
<xsl:include href="lookup.xsl"/>
<xsl:include href="paragraph.xsl"/>
<xsl:include href="simple.xsl"/>
<xsl:include href="whitespace.xsl"/>

<xsl:param name="library"/>

<xsl:variable name="root" select="'.'"/>

<xsl:template match="/document">
	<HTML>
		<HEAD>
			<TITLE><xsl:value-of select="@id"/> - <xsl:value-of select="document($library)/library/@name"/></TITLE>
			<LINK rel="stylesheet" type="text/css" href="{$root}/style.css"/>
		</HEAD>
		<BODY>
			<xsl:for-each select="section">
				<xsl:if test="preceding-sibling::section">
					<HR/>
				</xsl:if>
				<xsl:if test="@id">
					<H4><xsl:value-of select="@id"/></H4>
				</xsl:if>
				<xsl:apply-templates select="para"/>
			</xsl:for-each>
			<xsl:if test="@author">
				<xsl:call-template name="copyright"/>
			</xsl:if>
		</BODY>
	</HTML>
</xsl:template>

</xsl:stylesheet>
