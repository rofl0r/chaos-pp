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

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:spacing="/pp-book/spacing.xsl">

	<xsl:output method="html" doctype-public="-//W3C//DTD HTML 4.0 Strict//EN" indent="yes" encoding="UTF-8"/>

	<xsl:template name="spacing:apply">
		<xsl:param name="depth" select="0"/>
		<xsl:param name="nodeset" select="node()"/>
		<xsl:variable name="conditional-increment">
			<xsl:choose>
				<xsl:when test="count($nodeset/self::para | $nodeset/self::snippet | $nodeset/self::table) = count($nodeset) - count($nodeset/self::text()[normalize-space(.) = '']) - count($nodeset/self::comment())">
					<xsl:value-of select="0"/>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="1"/>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>
		<xsl:call-template name="spacing:traverse">
			<xsl:with-param name="depth" select="$depth + $conditional-increment"/>
			<xsl:with-param name="nodeset" select="$nodeset"/>
		</xsl:call-template>
	</xsl:template>

	<xsl:template name="spacing:traverse">
		<xsl:param name="depth"/>
		<xsl:param name="nodeset"/>
		<xsl:param name="collection" select="/@*"/>
		<xsl:param name="index" select="count($nodeset)"/>
		<xsl:choose>
			<xsl:when test="$index">
				<xsl:choose>
					<xsl:when test="name($nodeset[$index]) = 'para'">
						<xsl:call-template name="spacing:traverse">
							<xsl:with-param name="depth" select="$depth"/>
							<xsl:with-param name="nodeset" select="$nodeset"/>
							<xsl:with-param name="index" select="$index - 1"/>
						</xsl:call-template>
						<xsl:call-template name="spacing:apply">
							<xsl:with-param name="depth" select="$depth"/>
							<xsl:with-param name="nodeset" select="$nodeset[$index]/node()"/>
						</xsl:call-template>
						<xsl:if test="$collection">
							<xsl:call-template name="spacing:block">
								<xsl:with-param name="depth" select="$depth"/>
								<xsl:with-param name="fragment">
									<p><xsl:apply-templates select="$collection"/></p>
								</xsl:with-param>
							</xsl:call-template>
						</xsl:if>
					</xsl:when>
					<xsl:when test="name($nodeset[$index]) = 'snippet'">
						<xsl:call-template name="spacing:traverse">
							<xsl:with-param name="depth" select="$depth"/>
							<xsl:with-param name="nodeset" select="$nodeset"/>
							<xsl:with-param name="index" select="$index - 1"/>
						</xsl:call-template>
						<xsl:call-template name="spacing:block">
							<xsl:with-param name="depth" select="$depth + 1"/>
							<xsl:with-param name="fragment">
								<pre><xsl:apply-templates select="$nodeset[$index]/node()"/></pre>
							</xsl:with-param>
						</xsl:call-template>
						<xsl:if test="$collection">
							<xsl:call-template name="spacing:block">
								<xsl:with-param name="depth" select="$depth"/>
								<xsl:with-param name="fragment">
									<p><xsl:apply-templates select="$collection"/></p>
								</xsl:with-param>
							</xsl:call-template>
						</xsl:if>
					</xsl:when>
					<xsl:when test="name($nodeset[$index]) = 'table'">
						<xsl:call-template name="spacing:traverse">
							<xsl:with-param name="depth" select="$depth"/>
							<xsl:with-param name="nodeset" select="$nodeset"/>
							<xsl:with-param name="index" select="$index - 1"/>
						</xsl:call-template>
						<xsl:call-template name="spacing:block">
							<xsl:with-param name="depth" select="$depth + 1"/>
							<xsl:with-param name="fragment">
								<table cellspacing="0">
									<xsl:for-each select="$nodeset[$index]/row">
										<tr>
											<xsl:for-each select="column">
												<xsl:element name="td">
													<xsl:if test="@type">
														<xsl:attribute name="class"><xsl:value-of select="@type"/></xsl:attribute>
													</xsl:if>
													<xsl:apply-templates/>
												</xsl:element>
											</xsl:for-each>
										</tr>
									</xsl:for-each>
								</table>
							</xsl:with-param>
						</xsl:call-template>
						<xsl:if test="$collection">
							<xsl:call-template name="spacing:block">
								<xsl:with-param name="depth" select="$depth"/>
								<xsl:with-param name="fragment">
									<p><xsl:apply-templates select="$collection"/></p>
								</xsl:with-param>
							</xsl:call-template>
						</xsl:if>
					</xsl:when>
					<xsl:otherwise>
						<xsl:call-template name="spacing:traverse">
							<xsl:with-param name="depth" select="$depth"/>
							<xsl:with-param name="nodeset" select="$nodeset"/>
							<xsl:with-param name="collection" select="$nodeset[$index] | $collection"/>
							<xsl:with-param name="index" select="$index - 1"/>
						</xsl:call-template>
					</xsl:otherwise>
				</xsl:choose>
			</xsl:when>
			<xsl:when test="$collection">
				<xsl:call-template name="spacing:block">
					<xsl:with-param name="depth" select="$depth"/>
					<xsl:with-param name="fragment">
						<p><xsl:apply-templates select="$collection"/></p>
					</xsl:with-param>
				</xsl:call-template>
			</xsl:when>
		</xsl:choose>
	</xsl:template>
	<xsl:template name="spacing:block">
		<xsl:param name="depth"/>
		<xsl:param name="fragment"/>
		<xsl:if test="normalize-space($fragment) != ''">
			<xsl:choose>
				<xsl:when test="$depth != 1">
					<div>
						<xsl:call-template name="spacing:block">
							<xsl:with-param name="depth" select="$depth - 1"/>
							<xsl:with-param name="fragment" select="$fragment"/>
						</xsl:call-template>
					</div>
				</xsl:when>
				<xsl:otherwise>
					<xsl:copy-of select="$fragment"/>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:if>
	</xsl:template>

</xsl:stylesheet>
