<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="text" encoding="UTF-8"/>

<xsl:param name="destination"/>
<xsl:param name="source"/>

<xsl:template match="/library">
	mkdir -p <xsl:value-of select="concat($destination, '/', @name)"/>
	<xsl:for-each select="assoc">
		cp -u <xsl:value-of select="concat($source, '/', @id)"/><xsl:value-of select="' '"/><xsl:value-of select="concat($destination, '/', @id)"/>
	</xsl:for-each>
	<xsl:apply-templates>
		<xsl:with-param name="path" select="@name"/>
	</xsl:apply-templates>
</xsl:template>

<xsl:template match="directory">
	<xsl:param name="path"/>
	<xsl:variable name="new-path" select="concat($path, '/', @name)"/>
	mkdir -p <xsl:value-of select="concat($destination, '/', $new-path)"/>
	<xsl:apply-templates>
		<xsl:with-param name="path" select="$new-path"/>
	</xsl:apply-templates>
</xsl:template>

<xsl:template match="header">
	<xsl:param name="path"/>
	<xsl:variable name="enabled" select="'algorithm'"/>
	<xsl:if test="true() or contains(concat($path, '/', @name), $enabled)">
		<xsl:variable name="sans-suffix" select="concat($path, '/', substring-before(@name, '.'))"/>
		echo <xsl:value-of select="$sans-suffix"/>.html
		msxsl <xsl:value-of select="concat($source, '/', $sans-suffix)"/>.xml header.xsl -o <xsl:value-of select="concat($destination, '/', $sans-suffix)"/>.html $@
		<xsl:if test="count(assoc)">
			mkdir -p <xsl:value-of select="concat($destination, '/', $sans-suffix)"/>
			<xsl:for-each select="assoc">
				cp -u <xsl:value-of select="concat($source, '/', $sans-suffix, '/', @id)"/><xsl:value-of select="' '"/><xsl:value-of select="concat($destination, '/', $sans-suffix, '/', @id)"/>
			</xsl:for-each>
		</xsl:if>
	</xsl:if>
</xsl:template>

</xsl:stylesheet>
