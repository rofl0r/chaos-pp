<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<!-- <xsl:param name="library"/> -->
<!-- <xsl:variable name="root"/> -->

<xsl:import href="header-name.xsl"/>

<!-- unknown entities -->

<xsl:template name="unknown-entity">
	<xsl:param name="text"/>
	<CODE><A class="UNKNOWN" href="{$root}/unknown.html"><xsl:value-of select="$text"/></A></CODE>
</xsl:template>

<xsl:template match="*" priority="-2">
	<xsl:choose>
		<xsl:when test="contains(name(), '.')">
			<xsl:call-template name="unknown-entity">
				<xsl:with-param name="text"><xsl:call-template name="header-name"><xsl:with-param name="header-name" select="translate(name(), '-', '/')"/></xsl:call-template></xsl:with-param>
			</xsl:call-template>
		</xsl:when>
		<xsl:otherwise>
			<xsl:call-template name="unknown-entity">
				<xsl:with-param name="text"><xsl:value-of select="concat(document($library)/library/@macro-prefix, name())"/></xsl:with-param>
			</xsl:call-template>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

<!-- manual symbol lookup -->

<xsl:template name="manual">
	<xsl:param name="id" select="@id"/>
	<xsl:choose>
		<xsl:when test="contains($id, '.')">
			<xsl:variable name="nodeset" select="document('.library.xml')/library/header[@name = $id]"/>
			<xsl:choose>
				<xsl:when test="count($nodeset)">
					<CODE><A class="HEADER" href="{$root}/{substring-before($nodeset[1]/@name, '.')}.html"><xsl:call-template name="header-name"><xsl:with-param name="header-name" select="$id"/></xsl:call-template></A></CODE>
				</xsl:when>
				<xsl:otherwise>
					<xsl:call-template name="unknown-entity">
						<xsl:with-param name="text">&lt;<xsl:value-of select="$id"/>&gt;</xsl:with-param>
					</xsl:call-template>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:when>
		<xsl:otherwise>
			<xsl:variable name="nodeset" select="document('.library.xml')/library/macro[@id = $id]"/>
			<xsl:choose>
				<xsl:when test="count($nodeset)">
					<CODE><A class="{$nodeset[1]/@type}" href="{$root}/{substring-before($nodeset[1]/@header, '.')}.html#{$id}"><xsl:value-of select="concat(document($library)/library/@macro-prefix, $id)"/></A></CODE>
				</xsl:when>
				<xsl:otherwise>
					<xsl:call-template name="unknown-entity">
						<xsl:with-param name="text"><xsl:value-of select="concat(document($library)/library/@macro-prefix, $id)"/></xsl:with-param>
					</xsl:call-template>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

</xsl:stylesheet>
