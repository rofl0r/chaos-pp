<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:meta=".">

<xsl:output method="xml" indent="yes" encoding="UTF-8"/>
<xsl:namespace-alias stylesheet-prefix="meta" result-prefix="xsl"/>

<xsl:include href="header-name.xsl"/>

<xsl:param name="library"/>

<xsl:template name="to-upper">
	<xsl:param name="ch"/>
	<xsl:choose>
		<xsl:when test="$ch = 'a'">A</xsl:when>
		<xsl:when test="$ch = 'b'">B</xsl:when>
		<xsl:when test="$ch = 'c'">C</xsl:when>
		<xsl:when test="$ch = 'd'">D</xsl:when>
		<xsl:when test="$ch = 'e'">E</xsl:when>
		<xsl:when test="$ch = 'f'">F</xsl:when>
		<xsl:when test="$ch = 'g'">G</xsl:when>
		<xsl:when test="$ch = 'h'">H</xsl:when>
		<xsl:when test="$ch = 'i'">I</xsl:when>
		<xsl:when test="$ch = 'j'">J</xsl:when>
		<xsl:when test="$ch = 'k'">K</xsl:when>
		<xsl:when test="$ch = 'l'">L</xsl:when>
		<xsl:when test="$ch = 'm'">M</xsl:when>
		<xsl:when test="$ch = 'n'">N</xsl:when>
		<xsl:when test="$ch = 'o'">O</xsl:when>
		<xsl:when test="$ch = 'p'">P</xsl:when>
		<xsl:when test="$ch = 'q'">Q</xsl:when>
		<xsl:when test="$ch = 'r'">R</xsl:when>
		<xsl:when test="$ch = 's'">S</xsl:when>
		<xsl:when test="$ch = 't'">T</xsl:when>
		<xsl:when test="$ch = 'u'">U</xsl:when>
		<xsl:when test="$ch = 'v'">V</xsl:when>
		<xsl:when test="$ch = 'w'">W</xsl:when>
		<xsl:when test="$ch = 'x'">X</xsl:when>
		<xsl:when test="$ch = 'y'">U</xsl:when>
		<xsl:when test="$ch = 'z'">Z</xsl:when>
		<xsl:otherwise>
			<xsl:value-of select="$ch"/>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

<xsl:template name="capitalize">
	<xsl:param name="str"/>
	<xsl:call-template name="to-upper">
		<xsl:with-param name="ch" select="substring($str, 1, 1)"/>
	</xsl:call-template>
	<xsl:value-of select="substring($str, 2)"/>
</xsl:template>

<xsl:template match="/library">
	<meta:stylesheet version="1.0">
		<xsl:variable name="macro-prefix" select="document($library)/library/@macro-prefix"/>
		<xsl:for-each select="macro">
			<meta:template match="{@id}" name="{@id}">
				<xsl:choose>
					<xsl:when test="@display">
						<CODE><A href="{{$root}}/{substring-before(@header, '.')}.html#{@id}" class="{@type}"><xsl:value-of select="concat($macro-prefix, @display)"/></A></CODE>
					</xsl:when>
					<xsl:otherwise>
						<CODE><A href="{{$root}}/{substring-before(@header, '.')}.html#{@id}" class="{@type}"><xsl:value-of select="concat($macro-prefix, @id)"/></A></CODE>
					</xsl:otherwise>
				</xsl:choose>
			</meta:template>
		</xsl:for-each>
		<xsl:for-each select="alias">
			<meta:template match="{@id}" name="{@id}">
				<CODE><A href="{{$root}}/{substring-before(@header, '.')}.html#{@aliased-id}"><xsl:value-of select="concat($macro-prefix, @id)"/></A></CODE>
			</meta:template>
		</xsl:for-each>
		<xsl:for-each select="header">
			<meta:template match="{translate(@name, '/', '-')}">
				<CODE><A href="{{$root}}/{substring-before(@name, '.')}.html" class="HEADER"><xsl:call-template name="header-name"><xsl:with-param name="header-name" select="@name"/></xsl:call-template></A></CODE>
			</meta:template>
		</xsl:for-each>
		<meta:template match="link" priority="-1">
			<meta:message terminate="yes">[error: reference to unknown symbol "<meta:value-of select="@id"/>"]</meta:message>
		</meta:template>
		<xsl:for-each select="document/item">
			<xsl:variable name="capitalized">
				<xsl:call-template name="capitalize"><xsl:with-param name="str" select="@value"/></xsl:call-template>
			</xsl:variable>
			<meta:template match="link[@id = '{@value}']">
				<A href="{{$root}}/{../@path}.html"><xsl:value-of select="@value"/></A>
			</meta:template>
			<xsl:if test="@value != $capitalized">
				<meta:template match="link[@id = '{$capitalized}']">
					<A href="{{$root}}/{../@path}.html"><xsl:value-of select="$capitalized"/></A>
				</meta:template>
			</xsl:if>
		</xsl:for-each>
	</meta:stylesheet>
</xsl:template>

</xsl:stylesheet>
