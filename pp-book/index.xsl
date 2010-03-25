<?xml version="1.0" encoding="UTF-8"?>

<!-- **************************************************************************
     *                                                                        *
     *    (C) Copyright Paul Mensonides 2003-2005.                            *
     *                                                                        *
     *    Distributed under the Boost Software License, Version 1.0.          *
     *    (See accompanying file LICENSE).                                    *
     *                                                                        *
     *    See http://chaos-pp.sourceforge.net for the most recent version.    *
     *                                                                        *
     ************************************************************************** -->

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:copyright="/pp-book/copyright.xsl" xmlns:header-name="/pp-book/header-name.xsl">

	<xsl:import href="copyright.xsl"/>
	<xsl:import href="header-name.xsl"/>

	<xsl:output method="html" doctype-public="-//W3C//DTD HTML 4.0 Strict//EN" indent="yes" encoding="UTF-8"/>

	<xsl:param name="source"/>
	<xsl:param name="mode"/>

	<xsl:variable name="root" select="'.'"/>

	<xsl:template match="/library">
		<xsl:choose>
			<xsl:when test="$mode = 'documents'">
				<html>
					<head>
						<title>
							Document Index - <xsl:value-of select="@name"/>
						</title>
						<link rel="stylesheet" type="text/css" href="{$root}/style.css"/>
					</head>
					<body>
						<h4>Documents</h4>
						<ul>
							<xsl:comment>
								<xsl:value-of select="concat(count(document), ' entries')"/>
							</xsl:comment>
							<xsl:for-each select="document">
								<xsl:sort select="document(concat($source, '/', @path, '.xml'))/document/@id"/>
								<li>
									<a href="{$root}/{@path}.html">
										<xsl:value-of select="document(concat($source, '/', @path, '.xml'))/document/@id"/>
									</a>
								</li>
							</xsl:for-each>
						</ul>
						<xsl:call-template name="copyright:insert">
							<xsl:with-param name="author" select="'Paul Mensonides'"/>
							<xsl:with-param name="date" select="'2003-2005'"/>
						</xsl:call-template>
					</body>
				</html>
			</xsl:when>
			<xsl:when test="$mode = 'headers'">
				<html>
					<head>
						<title>
							Header Index - <xsl:value-of select="@name"/>
						</title>
						<link rel="stylesheet" type="text/css" href="{$root}/style.css"/>
					</head>
					<body>
						<h4>Headers</h4>
						<ul>
							<xsl:comment>
								<xsl:value-of select="concat(count(header), ' entries')"/>
							</xsl:comment>
							<xsl:for-each select="header">
								<xsl:sort select="@name"/>
								<li>
									<code>
										<a href="{$root}/{substring-before(@name, '.')}.html" class="header">
											<xsl:call-template name="header-name:format">
												<xsl:with-param name="file" select="@name"/>
											</xsl:call-template>
										</a>
									</code>
								</li>
							</xsl:for-each>
						</ul>
						<xsl:call-template name="copyright:insert">
							<xsl:with-param name="author" select="'Paul Mensonides'"/>
							<xsl:with-param name="date" select="'2003-2005'"/>
						</xsl:call-template>
					</body>
				</html>
			</xsl:when>
			<xsl:when test="$mode = 'primaries'">
				<html>
					<head>
						<title>
							Macro Index - <xsl:value-of select="@name"/>
						</title>
						<link rel="stylesheet" type="text/css" href="{$root}/style.css"/>
					</head>
					<body>
						<h4>
							Macros <small>
								<a href="{$root}/secondary.html">(show derivatives)</a>
							</small>
						</h4>
						<ul>
							<xsl:comment>
								<xsl:value-of select="concat(count(macro[@type = 'primary']), ' entries')"/>
							</xsl:comment>
							<xsl:for-each select="macro[@type = 'primary']">
								<xsl:sort select="@id"/>
								<li>
									<code>
										<a href="{$root}/{substring-before(@header, '.')}.html#{@id}" class="primary">
											<xsl:value-of select="concat(/library/@macro-prefix, @id)"/>
										</a>
									</code>
								</li>
							</xsl:for-each>
						</ul>
						<xsl:call-template name="copyright:insert">
							<xsl:with-param name="author" select="'Paul Mensonides'"/>
							<xsl:with-param name="date" select="'2003-2005'"/>
						</xsl:call-template>
					</body>
				</html>
			</xsl:when>
			<xsl:when test="$mode = 'secondaries'">
				<html>
					<head>
						<title>
							Macro Index - <xsl:value-of select="@name"/>
						</title>
						<link rel="stylesheet" type="text/css" href="{$root}/style.css"/>
					</head>
					<body>
						<h4>
							Macros <small>
								<a href="{$root}/primary.html">(hide derivatives)</a>
							</small>
						</h4>
						<ul>
							<xsl:comment>
								<xsl:value-of select="concat(count(macro), ' entries')"/>
							</xsl:comment>
							<xsl:for-each select="macro">
								<xsl:sort select="@id"/>
								<li>
									<code>
										<a href="{$root}/{substring-before(@header, '.')}.html#{@id}" class="{@type}">
											<xsl:value-of select="concat(/library/@macro-prefix, @id)"/>
										</a>
									</code>
								</li>
							</xsl:for-each>
						</ul>
						<xsl:call-template name="copyright:insert">
							<xsl:with-param name="author" select="'Paul Mensonides'"/>
							<xsl:with-param name="date" select="'2003-2005'"/>
						</xsl:call-template>
					</body>
				</html>
			</xsl:when>
		</xsl:choose>
	</xsl:template>

	<xsl:template match="/library2">
		<html>
			<head>
				<title>Document Index - <xsl:value-of select="@name"/></title>
				<link rel="stylesheet" type="text/css" href="{$root}/style.css"/>
			</head>
			<body>
				<h4>Documents</h4>
				<ul>
					<xsl:comment>
						<xsl:value-of select="concat(count(document), ' entries')"/>
					</xsl:comment>
					<xsl:for-each select="document">
						<xsl:sort select="document(concat($source, '/', @path, '.xml'))/document/@id"/>
						<li>
							<a href="{$root}/{@path}.html"><xsl:value-of select="document(concat($source, '/', @path, '.xml'))/document/@id"/></a>
						</li>
					</xsl:for-each>
				</ul>
				<xsl:call-template name="copyright:insert">
					<xsl:with-param name="author" select="'Paul Mensonides'"/>
					<xsl:with-param name="date" select="'2003-2005'"/>
				</xsl:call-template>
			</body>
		</html>
	</xsl:template>

	<xsl:template match="/library2" mode="headers">
		<html>
			<head>
				<title>Header Index - <xsl:value-of select="@name"/></title>
				<link rel="stylesheet" type="text/css" href="{$root}/style.css"/>
			</head>
			<body>
				<h4>Headers</h4>
				<ul>
					<xsl:comment>
						<xsl:value-of select="concat(count(header), ' entries')"/>
					</xsl:comment>
					<xsl:for-each select="header">
						<xsl:sort select="@name"/>
						<li>
							<code>
								<a href="{$root}/{substring-before(@name, '.')}.html" class="header">
									<xsl:call-template name="header-name:format">
										<xsl:with-param name="file" select="@name"/>
									</xsl:call-template>
								</a>
							</code>
						</li>
					</xsl:for-each>
				</ul>
				<xsl:call-template name="copyright:insert">
					<xsl:with-param name="author" select="'Paul Mensonides'"/>
					<xsl:with-param name="date" select="'2003-2005'"/>
				</xsl:call-template>
			</body>
		</html>
	</xsl:template>

	<xsl:template match="/library2" mode="primary">
		<html>
			<head>
				<title>Macro Index - <xsl:value-of select="@name"/></title>
				<link rel="stylesheet" type="text/css" href="{$root}/style.css"/>
			</head>
			<body>
				<h4>Macros <small><a href="{$root}/secondary.html">(show derivatives)</a></small></h4>
				<ul>
					<xsl:comment>
						<xsl:value-of select="concat(count(macro[@type = 'primary']), ' entries')"/>
					</xsl:comment>
					<xsl:for-each select="macro[@type = 'primary']">
						<xsl:sort select="@id"/>
						<li>
							<code>
								<a href="{$root}/{substring-before(@header, '.')}.html#{@id}" class="primary">
									<xsl:value-of select="concat(/library/@macro-prefix, @id)"/>
								</a>
							</code>
						</li>
					</xsl:for-each>
				</ul>
				<xsl:call-template name="copyright:insert">
					<xsl:with-param name="author" select="'Paul Mensonides'"/>
					<xsl:with-param name="date" select="'2003-2005'"/>
				</xsl:call-template>
			</body>
		</html>
	</xsl:template>

	<xsl:template match="/library2" mode="secondary">
		<html>
			<head>
				<title>Macro Index - <xsl:value-of select="@name"/></title>
				<link rel="stylesheet" type="text/css" href="{$root}/style.css"/>
			</head>
			<body>
				<h4>Macros <small><a href="{$root}/primary.html">(hide derivatives)</a></small></h4>
				<ul>
					<xsl:comment>
						<xsl:value-of select="concat(count(macro), ' entries')"/>
					</xsl:comment>
					<xsl:for-each select="macro">
						<xsl:sort select="@id"/>
						<li>
							<code>
								<a href="{$root}/{substring-before(@header, '.')}.html#{@id}" class="{@type}">
									<xsl:value-of select="concat(/library/@macro-prefix, @id)"/>
								</a>
							</code>
						</li>
					</xsl:for-each>
				</ul>
				<xsl:call-template name="copyright:insert">
					<xsl:with-param name="author" select="'Paul Mensonides'"/>
					<xsl:with-param name="date" select="'2003-2005'"/>
				</xsl:call-template>
			</body>
		</html>
	</xsl:template>

</xsl:stylesheet>
