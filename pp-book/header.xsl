<?xml version="1.0" encoding="UTF-8"?>

<!-- **************************************************************************
     *                                                                        *
     *    (C) Copyright Paul Mensonides 2003-2004.                            *
     *                                                                        *
     *    Distributed under the Boost Software License, Version 1.0.          *
     *    (See accompanying file LICENSE).                                    *
     *                                                                        *
     *    See http://chaos-pp.sourceforge.net for the most recent version.    *
     *                                                                        *
     ************************************************************************** -->

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:copyright="/pp-book/copyright.xsl" xmlns:lookup="/pp-book/lookup.xsl" xmlns:spacing="/pp-book/spacing.xsl" xmlns:whitespace="/pp-book/whitespace.xsl">

	<xsl:import href="copyright.xsl"/>
	<xsl:import href="lookup.xsl"/>
	<xsl:import href="spacing.xsl"/>
	<xsl:import href="whitespace.xsl"/>

	<xsl:output method="html" doctype-public="-//W3C//DTD HTML 4.0 Strict//EN" indent="yes" encoding="UTF-8"/>

	<xsl:include href=".symbol.xsl"/>
	<xsl:include href="common.xsl"/>

	<xsl:param name="library"/>

	<xsl:template name="make-root">
		<xsl:param name="path" select="/header/@name"/>
		<xsl:choose>
			<xsl:when test="contains($path, '/')">
				<xsl:text>../</xsl:text>
				<xsl:call-template name="make-root">
					<xsl:with-param name="path" select="substring-after($path, '/')"/>
				</xsl:call-template>
			</xsl:when>
			<xsl:otherwise>
				<xsl:text>.</xsl:text>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<xsl:variable name="root">
		<xsl:call-template name="make-root"/>
	</xsl:variable>

	<xsl:variable name="make-self">
		<xsl:choose>
			<xsl:when test="contains(substring-after(/header/@name, '/'), '/')">
				<xsl:value-of select="substring-after(substring-after(/header/@name, '/'), '/')"/>
			</xsl:when>
			<xsl:when test="contains(/header/@name, '/')">
				<xsl:value-of select="substring-after(/header/@name, '/')"/>
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="/header/@name"/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:variable>

	<xsl:template match="self">
		<code><xsl:value-of select="$make-self"/></code>
	</xsl:template>

	<xsl:template match="code/text() | listing/text() | snippet/text() | syntax/text()">
		<xsl:call-template name="whitespace:clean">
			<xsl:with-param name="text" select="."/>
		</xsl:call-template>
	</xsl:template>

	<xsl:template match="*" priority="-2">
		<xsl:call-template name="lookup:unknown-entity"/>
	</xsl:template>

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
					<h4>Headers</h4>
					<ul>
						<xsl:for-each select="$nodeset/directory[@name = $path]/header">
							<xsl:sort select="@name"/>
							<li><code><a class="header" href="{$root}/{$original}/{substring-before(@name, '.')}.html"><xsl:value-of select="@name"/></a></code></li>
						</xsl:for-each>
					</ul>
				</xsl:if>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

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
					<h4>See Also</h4>
					<ul>
						<xsl:for-each select="$nodeset">
							<xsl:sort select="@id"/>
							<xsl:if test="@id != $id">
								<xsl:choose>
									<xsl:when test="@display">
										<li><code><a class="primary" href="{$root}/{substring-before(@header, '.')}.html#{@id}"><xsl:value-of select="concat(document($library)/library/@macro-prefix, @display)"/></a></code></li>
									</xsl:when>
									<xsl:otherwise>
										<li><code><a class="primary" href="{$root}/{substring-before(@header, '.')}.html#{@id}"><xsl:value-of select="concat(document($library)/library/@macro-prefix, @id)"/></a></code></li>
									</xsl:otherwise>
								</xsl:choose>
							</xsl:if>
						</xsl:for-each>
					</ul>
				</xsl:if>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<xsl:template match="/">
		<html>
			<head>
				<title><xsl:value-of select="$make-self"/> - <xsl:value-of select="document('.library.xml')/library/@name"/></title>
				<link rel="stylesheet" type="text/css" href="{$root}/style.css"/>
			</head>
			<body>
				<xsl:apply-templates select="header"/>
				<xsl:call-template name="copyright:insert"/>
			</body>
		</html>
	</xsl:template>

	<xsl:template match="/header">
		<xsl:for-each select="overview">
			<p><xsl:apply-templates/></p>
		</xsl:for-each>
		<h4>Usage</h4>
		<pre class="box">#include <xsl:call-template name="lookup:manual"><xsl:with-param name="id" select="@name"/></xsl:call-template></pre>
		<xsl:if test="macro">
			<h4>Contents</h4>
			<ul>
				<xsl:for-each select="macro">
					<xsl:sort select="@id"/>
					<li><code><a class="primary" href="#{@id}"><xsl:value-of select="concat(document('.library.xml')/library/@macro-prefix, @id)"/></a></code></li>
				</xsl:for-each>
			</ul>
		</xsl:if>
		<xsl:apply-templates select="directory-listing"/>
		<xsl:apply-templates select="macro"/>
	</xsl:template>

	<xsl:template match="/header/macro | /header/macro//derivative">
		<hr/>
		<a name="{@id}"/>
		<xsl:element name="h3">
			<xsl:attribute name="class">
				<xsl:choose>
					<xsl:when test="name() = 'macro'">primary</xsl:when>
					<xsl:otherwise><xsl:value-of select="@class"/></xsl:otherwise>
				</xsl:choose>
			</xsl:attribute>
			<xsl:value-of select="concat(document('.library.xml')/library/@macro-prefix, @id)"/>
		</xsl:element>
		<xsl:for-each select="abstract">
			<p><xsl:apply-templates/></p>
		</xsl:for-each>
		<xsl:for-each select="usage">
			<h4>Usage <xsl:if test="count(@lang)"><small>- <xsl:value-of select="@lang"/> Specific</small></xsl:if></h4>
			<xsl:for-each select="syntax">
				<pre class="box"><xsl:apply-templates/></pre>
			</xsl:for-each>
			<xsl:if test="param">
				<dl>
					<xsl:for-each select="param">
						<dt>
							<xsl:choose>
								<xsl:when test="@optional = 1">[<var><xsl:value-of select="@id"/></var>]</xsl:when>
								<xsl:otherwise><var><xsl:value-of select="@id"/></var></xsl:otherwise>
							</xsl:choose>
						</dt>
						<dd>
							<xsl:call-template name="spacing:apply"/>
						</dd>
					</xsl:for-each>
				</dl>
			</xsl:if>
		</xsl:for-each>
		<xsl:variable name="nodeset" select="*[not(contains('abstract derivative listing usage x-reference', name()))] | text()[normalize-space(.) != '']"/>
		<xsl:if test="$nodeset">
			<h4>Remarks</h4>
			<xsl:call-template name="spacing:apply">
				<xsl:with-param name="depth" select="1"/>
				<xsl:with-param name="nodeset" select="$nodeset"/>
			</xsl:call-template>
		</xsl:if>
		<xsl:call-template name="group-lookup">
			<xsl:with-param name="nodeset" select="document('.library.xml')/library/macro[@id = current()/x-reference/@id]"/>
		</xsl:call-template>
		<xsl:if test="listing">
			<h4>Sample Code</h4>
			<xsl:for-each select="listing[1]">
				<pre class="box"><xsl:apply-templates/></pre>
			</xsl:for-each>
		</xsl:if>
		<xsl:apply-templates select="derivative"/>
	</xsl:template>

</xsl:stylesheet>
