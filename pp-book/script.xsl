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

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

	<xsl:output method="text" encoding="UTF-8"/>

	<xsl:template match="/library">
		# $1 == library specification file
		# $2 == source path
		# $3 == destination path
		# $4 == regular expression
		if
			echo license | grep -q "$4"
		then
			echo document: license.html
			msxsl license.xml document.xsl -o "$3"/license.html
		fi
		if
			echo unknown | grep -q "$4"
		then
			echo document: unknown.html
			msxsl unknown.xml document.xsl -o "$3"/unknown.html
		fi
		<xsl:apply-templates select="binary-file | directory | document | header">
			<xsl:with-param name="path" select="''"/>
		</xsl:apply-templates>
	</xsl:template>

	<xsl:template match="binary-file">
		<xsl:param name="path"/>
		cp "$2"/<xsl:value-of select="concat($path, @name)"/> "$3"/<xsl:value-of select="concat($path, @name)"/>
	</xsl:template>

	<xsl:template match="directory">
		<xsl:param name="path"/>
		mkdir -p "$3"/<xsl:value-of select="concat($path, @name)"/>
		<xsl:apply-templates select="binary-file | directory | header">
			<xsl:with-param name="path" select="concat($path, @name, '/')"/>
		</xsl:apply-templates>
	</xsl:template>

	<xsl:template match="document">
		<xsl:param name="path"/>
		if
			echo <xsl:value-of select="concat($path, @id)"/> | grep -q "$4"
		then
			echo document: <xsl:value-of select="concat($path, @id)"/>.html
			msxsl "$2"/<xsl:value-of select="concat($path, @id)"/>.xml document.xsl -o "$3"/<xsl:value-of select="concat($path, @id)"/>.html
		fi
	</xsl:template>

	<xsl:template match="header">
		<xsl:param name="path"/>
		<xsl:variable name="sans-suffix" select="concat($path, substring-before(@name, '.'))"/>
		if
			echo <xsl:value-of select="concat($path, @name)"/> | grep -q "$4"
		then
			echo <xsl:value-of select="$sans-suffix"/>.html
			msxsl "$2"/<xsl:value-of select="$sans-suffix"/>.xml .meta.xsl -o .temp.xml
			msxsl .temp.xml header.xsl -o "$3"/<xsl:value-of select="$sans-suffix"/>.html library="$1"
		fi
	</xsl:template>

</xsl:stylesheet>
