<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="html" doctype-public="-//W3C//DTD HTML 4.0 Strict//EN" indent="yes" encoding="UTF-8"/>

<xsl:include href="copyright.xsl"/>

<xsl:param name="library"/>
<xsl:param name="prefix"/>

<xsl:variable name="root" select="'.'"/>

<xsl:template match="/library">
	<HTML>
		<HEAD>
			<TITLE>Header Index - <xsl:value-of select="translate($library, ',', ' ')"/></TITLE>
			<LINK rel="stylesheet" type="text/css" href="style.css"/>
		</HEAD>
		<BODY>
			<H4>Headers</H4>
			<UL>
				<xsl:for-each select="header">
					<xsl:sort select="@name"/>
					<LI><CODE><A href="{$root}/{substring-before(@name, '.')}.html">&lt;<xsl:value-of select="@name"/>&gt;</A></CODE></LI>
				</xsl:for-each>
			</UL>
			<xsl:call-template name="copyright">
				<xsl:with-param name="author" select="'Paul Mensonides'"/>
				<xsl:with-param name="date" select="'2003-2004'"/>
			</xsl:call-template>
		</BODY>
	</HTML>
</xsl:template>

<xsl:template match="/library" mode="primary">
	<HTML>
		<HEAD>
			<TITLE>Macro Index - <xsl:value-of select="translate($library, ',', ' ')"/></TITLE>
			<LINK rel="stylesheet" type="text/css" href="style.css"/>
		</HEAD>
		<BODY>
			<H4>Macros <SMALL><A href="master.html">(show derivatives)</A></SMALL></H4>
			<UL>
				<xsl:for-each select="macro[@type = 'primary']">
					<xsl:sort select="@id"/>
					<LI><CODE><A href="{$root}/{substring-before(@header, '.')}.html#{@id}"><xsl:value-of select="concat($prefix, @id)"/></A></CODE></LI>
				</xsl:for-each>
			</UL>
			<xsl:call-template name="copyright">
				<xsl:with-param name="author" select="'Paul Mensonides'"/>
				<xsl:with-param name="date" select="'2003-2004'"/>
			</xsl:call-template>
		</BODY>
	</HTML>
</xsl:template>

<xsl:template match="/library" mode="secondary">
	<HTML>
		<HEAD>
			<TITLE>Macro Index - <xsl:value-of select="translate($library, ',', ' ')"/></TITLE>
			<LINK rel="stylesheet" type="text/css" href="style.css"/>
		</HEAD>
		<BODY>
			<H4>Macros <SMALL><A href="macros.html">(hide derivatives)</A></SMALL></H4>
			<UL>
				<xsl:for-each select="macro">
					<xsl:sort select="@id"/>
					<LI><CODE><A href="{$root}/{substring-before(@header, '.')}.html#{@id}"><xsl:value-of select="concat($prefix, @id)"/></A></CODE></LI>
				</xsl:for-each>
			</UL>
			<xsl:call-template name="copyright">
				<xsl:with-param name="author" select="'Paul Mensonides'"/>
				<xsl:with-param name="date" select="'2003-2004'"/>
			</xsl:call-template>
		</BODY>
	</HTML>
</xsl:template>

<xsl:template match="/register">
	<HTML>
		<HEAD>
			<TITLE>Document Index - <xsl:value-of select="translate($library, ',', ' ')"/></TITLE>
			<LINK rel="stylesheet" type="text/css" href="style.css"/>
		</HEAD>
		<BODY>
			<H4>Documents</H4>
			<UL>
				<xsl:for-each select="document">
					<xsl:sort select="@title"/>
					<!-- document titles need to be lookup up -->
					<LI><A href="{$root}/{@id}.html" class="LISTITEM"><xsl:value-of select="@title"/></A></LI>
				</xsl:for-each>
			</UL>
			<xsl:call-template name="copyright">
				<xsl:with-param name="author" select="'Paul Mensonides'"/>
				<xsl:with-param name="date" select="'2003-2004'"/>
			</xsl:call-template>
		</BODY>
	</HTML>
</xsl:template>

</xsl:stylesheet>
