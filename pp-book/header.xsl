<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="html" doctype-public="-//W3C//DTD HTML 4.0 Strict//EN" indent="yes" encoding="UTF-8"/>

<xsl:include href=".symbol.xsl"/>

<xsl:include href="copyright.xsl"/>
<xsl:include href="header-name.xsl"/>
<xsl:include href="lookup.xsl"/>
<xsl:include href="paragraph.xsl"/>
<xsl:include href="simple.xsl"/>
<xsl:include href="whitespace.xsl"/>

<xsl:param name="library"/>

<!-- globals -->

<xsl:template name="make-root">
	<xsl:param name="string" select="/header/@name"/>
	<xsl:choose>
		<xsl:when test="contains($string, '/')">../<xsl:call-template name="make-root"><xsl:with-param name="string" select="substring-after($string, '/')"/></xsl:call-template></xsl:when>
		<xsl:otherwise>.</xsl:otherwise>
	</xsl:choose>
</xsl:template>

<xsl:variable name="root">
	<xsl:call-template name="make-root"/>
</xsl:variable>

<!-- special operators -->

<xsl:variable name="make-self">
	<xsl:choose>
		<xsl:when test="contains(substring-after(/header/@name, '/'), '/')">
			<xsl:value-of select="substring-after(substring-after(/header/@name, '/'), '/')"/>
		</xsl:when>
		<xsl:otherwise>
			<xsl:value-of select="substring-after(/header/@name, '/')"/>
		</xsl:otherwise>
	</xsl:choose>
</xsl:variable>

<xsl:template match="self">
	<CODE><xsl:value-of select="$make-self"/></CODE>
</xsl:template>

<!-- directory listing -->

<xsl:template name="directory-listing" match="directory-listing">
	<xsl:param name="path" select="@path"/>
	<xsl:param name="original" select="@path"/>
	<xsl:param name="nodeset" select="document($library)/library"/>
	<xsl:choose>
		<xsl:when test="contains($path, '/')">
			<xsl:call-template name="directory-listing">
				<xsl:with-param name="path" select="substring-after($path, '/')"/>
				<xsl:with-param name="nodeset" select="$nodeset/directory[@name = substring-before($path, '/')]"/>
			</xsl:call-template>
		</xsl:when>
		<xsl:otherwise>
			<xsl:if test="$nodeset/directory[@name = $path]/header">
				<H4>Headers</H4>
				<UL>
					<xsl:for-each select="$nodeset/directory[@name = $path]/header">
						<xsl:sort select="@name"/>
						<LI><CODE><A class="HEADER" href="{$root}/{$original}/{substring-before(@name, '.')}.html"><xsl:value-of select="@name"/></A></CODE></LI>
					</xsl:for-each>
				</UL>
			</xsl:if>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

<!-- group lookup -->

<xsl:template name="group-lookup">
	<xsl:param name="id" select="@id"/>
	<xsl:param name="nodeset" select="node()[false()]"/>
	<xsl:param name="groups" select="document('.library.xml')/library/macro[@id = $id]/group"/>
	<xsl:choose>
		<xsl:when test="count($groups)">
			<xsl:call-template name="group-lookup">
				<xsl:with-param name="id" select="$id"/>
				<xsl:with-param name="nodeset" select="$nodeset | document('.library.xml')/library/macro[group[@id = $groups[1]/@id]]"/>
				<xsl:with-param name="groups" select="$groups/following-sibling::group"/>
			</xsl:call-template>
		</xsl:when>
		<xsl:otherwise>
			<xsl:if test="count($nodeset) &gt; 1 or $nodeset[1]/@id != $id">
				<H4>See Also</H4>
				<UL>
					<xsl:for-each select="$nodeset">
						<xsl:sort select="@id"/>
						<xsl:if test="@id != $id">
							<xsl:choose>
								<xsl:when test="@display">
									<LI><CODE><A class="PRIMARY" href="{$root}/{substring-before(@header, '.')}.html#{@id}"><xsl:value-of select="concat(document($library)/library/@macro-prefix, @display)"/></A></CODE></LI>
								</xsl:when>
								<xsl:otherwise>
									<LI><CODE><A class="PRIMARY" href="{$root}/{substring-before(@header, '.')}.html#{@id}"><xsl:value-of select="concat(document($library)/library/@macro-prefix, @id)"/></A></CODE></LI>
								</xsl:otherwise>
							</xsl:choose>
						</xsl:if>
					</xsl:for-each>
				</UL>
			</xsl:if>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

<!-- document-related structure -->

<xsl:template match="/">
	<HTML>
		<HEAD>
			<TITLE><xsl:value-of select="$make-self"/> - <xsl:value-of select="document($library)/library/@name"/></TITLE>
			<LINK rel="stylesheet" type="text/css" href="{$root}/style.css"/>
		</HEAD>
		<BODY>
			<xsl:apply-templates select="header"/>
			<xsl:call-template name="copyright"/>
		</BODY>
	</HTML>
</xsl:template>

<!-- header-related structure -->

<xsl:template match="/header">
	<xsl:for-each select="overview">
		<SPAN><xsl:apply-templates/></SPAN>
	</xsl:for-each>
	<H4>Usage</H4>
	<SAMP>#include <xsl:call-template name="manual"><xsl:with-param name="id" select="@name"/></xsl:call-template></SAMP>
	<xsl:if test="macro">
		<H4>Contents</H4>
		<UL>
			<xsl:for-each select="macro">
				<xsl:sort select="@id"/>
				<xsl:choose>
					<xsl:when test="@display">
						<LI><CODE><A class="PRIMARY" href="#{@id}"><xsl:value-of select="concat(document($library)/library/@macro-prefix, @display)"/></A></CODE></LI>
					</xsl:when>
					<xsl:otherwise>
						<LI><CODE><A class="PRIMARY" href="#{@id}"><xsl:value-of select="concat(document($library)/library/@macro-prefix, @id)"/></A></CODE></LI>
					</xsl:otherwise>
				</xsl:choose>
			</xsl:for-each>
		</UL>
	</xsl:if>
	<xsl:apply-templates select="directory-listing"/>
	<xsl:apply-templates select="macro"/>
</xsl:template>

<!-- macro-related structure -->

<xsl:template match="/header/macro | /header/macro//derivative">
	<HR/>
	<A name="{@id}"/>
	<xsl:element name="H3">
		<xsl:attribute name="class">
			<xsl:choose>
				<xsl:when test="name() = 'macro'">PRIMARY</xsl:when>
				<xsl:otherwise><xsl:value-of select="@class"/></xsl:otherwise>
			</xsl:choose>
		</xsl:attribute>
		<xsl:choose>
			<xsl:when test="@display">
				<xsl:value-of select="concat(document($library)/library/@macro-prefix, @display)"/>
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="concat(document($library)/library/@macro-prefix, @id)"/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:element>
	<xsl:for-each select="abstract[1]">
		<SPAN><xsl:apply-templates/></SPAN>
	</xsl:for-each>
	<xsl:for-each select="usage">
		<H4>Usage <xsl:if test="count(@lang)"><SMALL>- <xsl:value-of select="@lang"/> Specific</SMALL></xsl:if></H4>
		<xsl:for-each select="syntax[1]">
			<SAMP><xsl:apply-templates/></SAMP>
		</xsl:for-each>
		<xsl:if test="param">
			<DL>
				<xsl:for-each select="param">
					<DT>
						<xsl:choose>
							<xsl:when test="@optional = 1">[<VAR><xsl:value-of select="@id"/></VAR>]</xsl:when>
							<xsl:otherwise><VAR><xsl:value-of select="@id"/></VAR></xsl:otherwise>
						</xsl:choose>
					</DT>
					<DD><xsl:apply-templates/></DD>
				</xsl:for-each>
			</DL>
		</xsl:if>
	</xsl:for-each>
	<xsl:if test="count(para)">
		<H4>Remarks</H4>
		<xsl:apply-templates select="para"/>
	</xsl:if>
	<xsl:call-template name="group-lookup">
		<xsl:with-param name="nodeset" select="document('.library.xml')/library/macro[@id = current()/x-reference/@id]"/>
	</xsl:call-template>
	<xsl:if test="count(listing)">
		<H4>Sample Code</H4>
		<xsl:for-each select="listing[1]">
			<SAMP><xsl:apply-templates/></SAMP>
		</xsl:for-each>
	</xsl:if>
	<xsl:apply-templates select="derivative"/>
</xsl:template>

</xsl:stylesheet>
