<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="html" doctype-public="-//W3C//DTD HTML 4.0 Strict//EN" indent="yes" encoding="UTF-8"/>

<xsl:include href="copyright.xsl"/>
<xsl:include href="header-name.xsl"/>

<xsl:param name="library"/>
<xsl:param name="source"/>

<xsl:variable name="root" select="'.'"/>

<xsl:template match="/library">
	<HTML>
		<HEAD>
			<TITLE>Document Index - <xsl:value-of select="document($library)/library/@name"/></TITLE>
			<LINK rel="stylesheet" type="text/css" href="{$root}/style.css"/>
		</HEAD>
		<BODY>
			<H4>Documents</H4>
			<UL>
				<xsl:for-each select="document">
					<xsl:sort select="document(concat($source, '/', @path, '.xml'))/document/@id"/>
					<LI><A href="{$root}/{@path}.html"><xsl:value-of select="document(concat($source, '/', @path, '.xml'))/document/@id"/></A></LI>
				</xsl:for-each>
			</UL>
			<xsl:call-template name="copyright">
				<xsl:with-param name="author" select="'Paul Mensonides'"/>
				<xsl:with-param name="date" select="'2003-2004'"/>
			</xsl:call-template>
		</BODY>
	</HTML>
</xsl:template>

<xsl:template match="/library" mode="headers">
	<HTML>
		<HEAD>
			<TITLE>Header Index - <xsl:value-of select="document($library)/library/@name"/></TITLE>
			<LINK rel="stylesheet" type="text/css" href="{$root}/style.css"/>
		</HEAD>
		<BODY>
			<xsl:choose>
				<xsl:when test="false()">
					<H4>Headers <SMALL>(<xsl:value-of select="count(header)"/>)</SMALL></H4>
				</xsl:when>
				<xsl:otherwise>
					<H4>Headers</H4>
				</xsl:otherwise>
			</xsl:choose>
			<UL>
				<xsl:for-each select="header">
					<xsl:sort select="@name"/>
					<LI><CODE><A href="{$root}/{substring-before(@name, '.')}.html" class="HEADER"><xsl:call-template name="header-name"><xsl:with-param name="header-name" select="@name"/></xsl:call-template></A></CODE></LI>
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
			<TITLE>Macro Index - <xsl:value-of select="document($library)/library/@name"/></TITLE>
			<LINK rel="stylesheet" type="text/css" href="{$root}/style.css"/>
		</HEAD>
		<BODY>
			<xsl:choose>
				<xsl:when test="false()">
					<H4>Macros <SMALL>(<xsl:value-of select="count(macro[@type = 'PRIMARY'])"/>)</SMALL></H4>
				</xsl:when>
				<xsl:otherwise>
					<H4>Macros <SMALL><A href="{$root}/master.html">(show derivatives)</A></SMALL></H4>
				</xsl:otherwise>
			</xsl:choose>
			<UL>
				<xsl:for-each select="macro[@type = 'PRIMARY']">
					<xsl:sort select="@id"/>
					<xsl:choose>
						<xsl:when test="@display">
							<LI><CODE><A href="{$root}/{substring-before(@header, '.')}.html#{@id}" class="PRIMARY"><xsl:value-of select="concat(document($library)/library/@macro-prefix, @display)"/></A></CODE></LI>
						</xsl:when>
						<xsl:otherwise>
							<LI><CODE><A href="{$root}/{substring-before(@header, '.')}.html#{@id}" class="PRIMARY"><xsl:value-of select="concat(document($library)/library/@macro-prefix, @id)"/></A></CODE></LI>
						</xsl:otherwise>
					</xsl:choose>
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
			<TITLE>Macro Index - <xsl:value-of select="document($library)/library/@name"/></TITLE>
			<LINK rel="stylesheet" type="text/css" href="{$root}/style.css"/>
		</HEAD>
		<BODY>
			<xsl:choose>
				<xsl:when test="false()">
					<H4>Macros <SMALL>(<xsl:value-of select="count(macro)"/>)</SMALL></H4>
				</xsl:when>
				<xsl:otherwise>
					<H4>Macros <SMALL><A href="{$root}/macros.html">(hide derivatives)</A></SMALL></H4>
				</xsl:otherwise>
			</xsl:choose>
			<UL>
				<xsl:for-each select="macro">
					<xsl:sort select="@id"/>
					<xsl:choose>
						<xsl:when test="@display">
							<LI><CODE><A href="{$root}/{substring-before(@header, '.')}.html#{@id}" class="PRIMARY"><xsl:value-of select="concat(document($library)/library/@macro-prefix, @display)"/></A></CODE></LI>
						</xsl:when>
						<xsl:otherwise>
							<LI><CODE><A href="{$root}/{substring-before(@header, '.')}.html#{@id}" class="PRIMARY"><xsl:value-of select="concat(document($library)/library/@macro-prefix, @id)"/></A></CODE></LI>
						</xsl:otherwise>
					</xsl:choose>
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
