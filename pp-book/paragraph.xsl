<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="html" doctype-public="-//W3C//DTD HTML 4.0 Strict//EN" indent="yes" encoding="UTF-8"/>

<xsl:template match="para" priority="-1">
	<DIV><xsl:apply-templates/></DIV>
</xsl:template>

<xsl:template match="*" mode="typeof">element</xsl:template>
<xsl:template match="text()" mode="typeof">text</xsl:template>

<xsl:template name="push">
	<xsl:param name="nodeset" select="preceding-sibling::node()"/>
	<xsl:choose>
		<xsl:when test="count($nodeset) != 0">
			<xsl:variable name="type">
				<xsl:apply-templates select="$nodeset[last()]" mode="typeof"/>
			</xsl:variable>
			<xsl:choose>
				<xsl:when test="$type = 'text'">
					<xsl:choose>
						<xsl:when test="normalize-space($nodeset[last()]) = ''">
							<xsl:call-template name="push">
								<xsl:with-param name="nodeset" select="$nodeset[last()]/preceding-sibling::node()"/>
							</xsl:call-template>
						</xsl:when>
						<xsl:otherwise>PUSH</xsl:otherwise>
					</xsl:choose>
				</xsl:when>
			</xsl:choose>
		</xsl:when>
	</xsl:choose>
</xsl:template>

<xsl:template name="pull">
	<xsl:param name="nodeset" select="following-sibling::node()"/>
	<xsl:choose>
		<xsl:when test="count($nodeset) != 0">
			<xsl:variable name="type">
				<xsl:apply-templates select="$nodeset[1]" mode="typeof"/>
			</xsl:variable>
			<xsl:choose>
				<xsl:when test="$type = 'text'">
					<xsl:choose>
						<xsl:when test="normalize-space($nodeset[1]) = ''">
							<xsl:call-template name="pull">
								<xsl:with-param name="nodeset" select="$nodeset[1]/following-sibling::node()"/>
							</xsl:call-template>
						</xsl:when>
					</xsl:choose>
				</xsl:when>
			</xsl:choose>
		</xsl:when>
		<xsl:otherwise>PULL</xsl:otherwise>
	</xsl:choose>
</xsl:template>

<xsl:template match="param/para">
	<xsl:variable name="push"><xsl:call-template name="push"/></xsl:variable>
	<xsl:variable name="pull"><xsl:call-template name="pull"/></xsl:variable>
	<xsl:choose>
		<xsl:when test="concat($push, $pull) = ''">
			<SPAN><xsl:apply-templates/></SPAN>
		</xsl:when>
		<xsl:otherwise>
			<SPAN class="{concat($push, $pull)}"><xsl:apply-templates/></SPAN>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

<xsl:template match="para/para">
	<xsl:variable name="push"><xsl:call-template name="push"/></xsl:variable>
	<xsl:variable name="pull"><xsl:call-template name="pull"/></xsl:variable>
	<xsl:choose>
		<xsl:when test="concat($push, $pull) = ''">
			<DIV><xsl:apply-templates/></DIV>
		</xsl:when>
		<xsl:otherwise>
			<DIV class="{concat($push, $pull)}"><xsl:apply-templates/></DIV>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

<xsl:template match="section/para">
	<xsl:choose>
		<xsl:when test="count(../@id)">
			<DIV><xsl:apply-templates/></DIV>
		</xsl:when>
		<xsl:otherwise>
			<DIV class="TOP"><xsl:apply-templates/></DIV>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

<xsl:template match="snippet">
	<xsl:variable name="push"><xsl:call-template name="push"/></xsl:variable>
	<xsl:variable name="pull"><xsl:call-template name="pull"/></xsl:variable>
	<xsl:choose>
		<xsl:when test="concat($push, $pull) = ''">
			<DIV><PRE><xsl:apply-templates/></PRE></DIV>
		</xsl:when>
		<xsl:otherwise>
			<DIV class="{concat($push, $pull)}"><PRE><xsl:apply-templates/></PRE></DIV>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

</xsl:stylesheet>
