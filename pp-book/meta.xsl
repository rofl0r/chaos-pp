<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:meta=".">

<xsl:output method="xml" indent="yes" encoding="UTF-8"/>
<xsl:namespace-alias stylesheet-prefix="meta" result-prefix="xsl"/>

<xsl:param name="source"/>

<xsl:template match="/library">
	<meta:stylesheet version="1.0">
		<meta:output method="xml" indent="yes" encoding="UTF-8"/>
		<meta:template match="*" priority="-1">
			<meta:element name="{{name()}}">
				<meta:for-each select="@*">
					<meta:attribute name="{{name()}}"><meta:value-of select="."/></meta:attribute>
				</meta:for-each>
				<meta:apply-templates/>
			</meta:element>
		</meta:template>
		<xsl:for-each select="derivative-spec">
			<xsl:apply-templates select="document(concat($source, '/', @href))/derivative-spec"/>
		</xsl:for-each>
	</meta:stylesheet>
</xsl:template>

<xsl:template match="/derivative-spec">
	<meta:template match="macro//derivative[substring-after(@id, ../@id) = '{@suffix}']">
		<derivative id="{{@id}}" class="{@class}">
			<xsl:apply-templates select="abstract"/>
			<xsl:choose>
				<xsl:when test="extended-usage">
					<xsl:apply-templates select="extended-usage[1]"/>
				</xsl:when>
				<xsl:otherwise>
					<xsl:for-each select="usage">
						<meta:element name="usage">
							<meta:if test="@lang">
								<meta:attribute name="lang"><meta:value-of select="@lang"/></meta:attribute>
							</meta:if>
							<xsl:apply-templates/>
						</meta:element>
					</xsl:for-each>
				</xsl:otherwise>
			</xsl:choose>
			<xsl:apply-templates select="pre-para"/>
			<meta:apply-templates select="para"/>
			<xsl:apply-templates select="post-para"/>
			<meta:apply-templates select="listing"/>
			<meta:apply-templates select="derivative"/>
		</derivative>
	</meta:template>
</xsl:template>

<xsl:template match="extended-usage">
	<meta:for-each select="usage">
		<meta:element name="usage">
			<meta:if test="@lang">
				<meta:attribute name="lang"><meta:value-of select="@lang"/></meta:attribute>
			</meta:if>
			<meta:apply-templates select="syntax[1]"/>
			<xsl:for-each select="pre-param">
				<xsl:element name="param">
					<xsl:for-each select="@*">
						<xsl:attribute name="{name()}"><xsl:value-of select="."/></xsl:attribute>
					</xsl:for-each>
					<xsl:apply-templates/>
				</xsl:element>
			</xsl:for-each>
			<meta:variable name="position" select="position()"/>
			<meta:copy-of select="ancestor::macro/usage[position() = $position]/param"/>
			<xsl:for-each select="post-param">
				<xsl:element name="param">
					<xsl:for-each select="@*">
						<xsl:attribute name="{name()}"><xsl:value-of select="."/></xsl:attribute>
					</xsl:for-each>
					<xsl:apply-templates/>
				</xsl:element>
			</xsl:for-each>
		</meta:element>
	</meta:for-each>
</xsl:template>

<xsl:template match="*" priority="-1">
	<xsl:element name="{name()}">
		<xsl:for-each select="@*">
			<xsl:attribute name="{name()}"><xsl:value-of select="."/></xsl:attribute>
		</xsl:for-each>
		<xsl:apply-templates/>
	</xsl:element>
</xsl:template>

<xsl:template match="pre-para | post-para">
	<para><xsl:apply-templates/></para>
</xsl:template>

<xsl:template match="current"><meta:element name="{{@id}}"/></xsl:template>
<xsl:template match="parent"><meta:element name="{{../@id}}"/></xsl:template>

<xsl:template match="sibling">
	<xsl:element name="xsl:element">
		<xsl:attribute name="name">{concat(../@id, '<xsl:value-of select="@suffix"/>')}</xsl:attribute>
	</xsl:element>
</xsl:template>

</xsl:stylesheet>
