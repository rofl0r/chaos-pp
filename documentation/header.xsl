<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="html" doctype-public="-//W3C//DTD HTML 4.0 Strict//EN" indent="yes" encoding="UTF-8"/>

<xsl:include href="_register.xsl"/>
<xsl:include href="_symbol.xsl"/>

<xsl:include href="copyright.xsl"/>
<xsl:include href="whitespace.xsl"/>

<!-- globals -->

<xsl:template name="make-base-filename">
	<xsl:param name="string" select="/header/@name"/>
	<xsl:choose>
		<xsl:when test="contains($string, '/')">
			<xsl:call-template name="make-base-filename">
				<xsl:with-param name="string" select="substring-after($string, '/')"/>
			</xsl:call-template>
		</xsl:when>
		<xsl:otherwise>
			<xsl:value-of select="substring-before($string, '.')"/>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

<xsl:variable name="base-filename">
	<xsl:call-template name="make-base-filename"/>
</xsl:variable>

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
		<xsl:when test="contains(/header/@name, 'chaos/preprocessor/')">
			<xsl:value-of select="substring-after(/header/@name, 'chaos/preprocessor/')"/>
		</xsl:when>
		<xsl:otherwise>
			<xsl:value-of select="substring-after(/header/@name, '/')"/>
		</xsl:otherwise>
	</xsl:choose>
</xsl:variable>

<xsl:template match="self">
	<CODE><xsl:value-of select="$make-self"/></CODE>
</xsl:template>

<xsl:template name="unknown-entity">
	<xsl:param name="text"/>
	<!--<xsl:message terminate="yes">unknown symbol: <xsl:value-of select="$text"/></xsl:message>-->
	<CODE><A class="unknown" href="{$root}/unknown.html"><xsl:value-of select="$text"/></A></CODE>
</xsl:template>

<xsl:template match="*" priority="-2">
	<xsl:choose>
		<xsl:when test="contains(name(), '.')">
			<xsl:call-template name="unknown-entity">
				<xsl:with-param name="text">&lt;<xsl:value-of select="translate(name(), '-', '/')"/>&gt;</xsl:with-param>
			</xsl:call-template>
		</xsl:when>
		<xsl:otherwise>
			<xsl:call-template name="unknown-entity">
				<xsl:with-param name="text">CHAOS_PP_<xsl:value-of select="name()"/></xsl:with-param>
			</xsl:call-template>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

<!-- association links -->

<xsl:template match="absolute-assoc">
	<A href="{@id}"><xsl:apply-templates/></A>
</xsl:template>

<xsl:template match="relative-assoc">
	<A href="{$base-filename}/{@id}"><xsl:apply-templates/></A>
</xsl:template>

<xsl:template match="x-alpha">
	<A href="{$root}/x-alpha.gif">α</A>
</xsl:template>

<xsl:template match="x-beta">
	<A href="{$root}/x-beta.gif">β</A>
</xsl:template>

<!-- identities -->

<xsl:template match="code | em | sub | sup | var">
	<xsl:element name="{name()}">
		<xsl:apply-templates/>
	</xsl:element>
</xsl:template>

<xsl:template match="x-var">
	<VAR class="EXTERNAL"><xsl:apply-templates/></VAR>
</xsl:template>

<!-- manual symbol lookup -->

<xsl:template name="manual">
	<xsl:param name="id" select="@id"/>
	<xsl:choose>
		<xsl:when test="contains($id, '.')">
			<xsl:variable name="nodeset" select="document('_library.xml')/library/header[@name = $id]"/>
			<xsl:choose>
				<xsl:when test="count($nodeset)">
					<CODE><A class="header" href="{$root}/{substring-before($nodeset[1]/@name, '.')}.html">&lt;<xsl:value-of select="$id"/>&gt;</A></CODE>
				</xsl:when>
				<xsl:otherwise>
					<xsl:call-template name="unknown-entity">
						<xsl:with-param name="text">&lt;<xsl:value-of select="$id"/>&gt;</xsl:with-param>
					</xsl:call-template>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:when>
		<xsl:otherwise>
			<xsl:variable name="nodeset" select="document('_library.xml')/library/macro[@id = $id]"/>
			<xsl:choose>
				<xsl:when test="count($nodeset)">
					<CODE><A class="{$nodeset[1]/@type}" href="{$root}/{substring-before($nodeset[1]/@header, '.')}.html#{$id}">CHAOS_PP_<xsl:value-of select="$id"/></A></CODE>
				</xsl:when>
				<xsl:otherwise>
					<xsl:call-template name="unknown-entity">
						<xsl:with-param name="text">CHAOS_PP_<xsl:value-of select="$id"/></xsl:with-param>
					</xsl:call-template>
				</xsl:otherwise>
			</xsl:choose>
		</xsl:otherwise>
	</xsl:choose>
</xsl:template>

<xsl:template name="manual-parent">
	<xsl:param name="id" select="../@id"/>
	<xsl:call-template name="manual">
		<xsl:with-param name="id" select="$id"/>
	</xsl:call-template>
</xsl:template>

<!-- directory listing -->

<xsl:template name="directory-listing" match="directory-listing">
	<xsl:param name="path" select="substring-after(@path, 'chaos/')"/>
	<xsl:param name="original" select="@path"/>
	<xsl:param name="nodeset" select="document('library.xml')/library"/>
	<xsl:choose>
		<xsl:when test="contains($path, '/')">
			<xsl:call-template name="directory-listing">
				<xsl:with-param name="path" select="substring-after($path, '/')"/>
				<xsl:with-param name="nodeset" select="$nodeset/directory[@name = substring-before($path, '/')]"/>
			</xsl:call-template>
		</xsl:when>
		<xsl:otherwise>
			<xsl:variable name="sans-prefix" select="substring-after($original, 'chaos/preprocessor/')"/>
			<xsl:variable name="separator">
				<xsl:if test="string-length($sans-prefix)">/</xsl:if>
			</xsl:variable>
			<xsl:if test="$nodeset/directory[@name = $path]/header">
				<H4>Headers</H4>
				<UL>
					<xsl:for-each select="$nodeset/directory[@name = $path]/header">
						<xsl:sort select="@name"/>
						<LI><CODE><A class="header" href="{$root}/{$original}/{substring-before(@name, '.')}.html"><xsl:value-of select="@name"/></A></CODE></LI>
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
	<xsl:param name="groups" select="document('_library.xml')/library/macro[@id = $id]/group"/>
	<xsl:choose>
		<xsl:when test="count($groups)">
			<xsl:call-template name="group-lookup">
				<xsl:with-param name="id" select="$id"/>
				<xsl:with-param name="nodeset" select="$nodeset | document('_library.xml')/library/macro[group[@id = $groups[1]/@id]]"/>
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
							<LI><CODE><A class="primary" href="{$root}/{substring-before(@header, '.')}.html#{@id}">CHAOS_PP_<xsl:value-of select="@id"/></A></CODE></LI>
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
			<TITLE><xsl:value-of select="$make-self"/> - Chaos Preprocessor Library</TITLE>
			<LINK rel="stylesheet" type="text/css" href="{$root}/style.css"/>
		</HEAD>
		<BODY>
			<xsl:apply-templates select="header"/>
			<xsl:call-template name="copyright">
				<xsl:with-param name="author" select="/header/@author"/>
				<xsl:with-param name="date" select="/header/@date"/>
			</xsl:call-template>
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
			<!--<xsl:for-each select="macro | macro//derivative">-->
				<xsl:sort select="@id"/>
				<LI><CODE><A class="primary" href="#{@id}">CHAOS_PP_<xsl:value-of select="@id"/></A></CODE></LI>
			</xsl:for-each>
		</UL>
	</xsl:if>
	<xsl:apply-templates select="directory-listing"/>
	<xsl:apply-templates select="macro"/>
</xsl:template>

<!-- macro-related structure -->

<xsl:template match="/header/macro">
	<HR/>
	<A name="{@id}"/>
	<H3 class="PRIMARY">CHAOS_PP_<xsl:value-of select="@id"/></H3>
	<xsl:for-each select="abstract">
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
		<xsl:with-param name="nodeset" select="document('_library.xml')/library/macro[@id = current()/x-reference/@id]"/>
	</xsl:call-template>
	<xsl:if test="count(listing)">
		<H4>Sample Code</H4>
		<xsl:for-each select="listing[1]">
			<SAMP><xsl:apply-templates/></SAMP>
		</xsl:for-each>
	</xsl:if>
	<xsl:apply-templates select="derivative"/>
</xsl:template>

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

<!-- derivative entities -->

<xsl:template match="derivative[substring-after(@id, ../@id) = '_ID']">
	<xsl:variable name="current"><xsl:call-template name="manual"/></xsl:variable>
	<xsl:variable name="parent"><xsl:call-template name="manual-parent"/></xsl:variable>
	<HR/>
	<A name="{@id}"/>
	<H3 class="SECONDARY">CHAOS_PP_<xsl:value-of select="@id"/></H3>
	<SPAN>
		The <xsl:copy-of select="$current"/> macro indirectly expands to <xsl:copy-of select="$parent"/>.
	</SPAN>
	<H4>Usage <xsl:if test="count(@lang)"><SMALL>- <xsl:value-of select="@lang"/> Specific</SMALL></xsl:if></H4>
	<SAMP><xsl:copy-of select="$current"/>()</SAMP>
	<H4>Remarks</H4>
	<DIV>
		<xsl:choose>
			<xsl:when test="ancestor::macro/@type = 'indirect'">
				This macro effectively allows <xsl:copy-of select="$parent"/> to pass through itself without becoming disabled.
			</xsl:when>
			<xsl:when test="ancestor::macro/@type = 'object'">
				This macro effectively allows <xsl:copy-of select="$parent"/> to be passed around without expansion.
			</xsl:when>
			<xsl:otherwise>
				This macro exists only for uniformity with other macros that require indirect invocation.
			</xsl:otherwise>
		</xsl:choose>
	</DIV>
	<xsl:if test="count(listing)">
		<H4>Sample Code</H4>
		<xsl:for-each select="listing[1]">
			<SAMP><xsl:apply-templates/></SAMP>
		</xsl:for-each>
	</xsl:if>
</xsl:template>

<xsl:template match="derivative[substring-after(@id, ../@id) = '_']">
	<xsl:variable name="current"><xsl:call-template name="manual"/></xsl:variable>
	<xsl:variable name="parent"><xsl:call-template name="manual-parent"/></xsl:variable>
	<HR/>
	<A name="{@id}"/>
	<H3 class="SECONDARY">CHAOS_PP_<xsl:value-of select="@id"/></H3>
	<SPAN>
		The <xsl:copy-of select="$current"/> macro expands to a <A href="{$root}/lambda.html">λ-expression</A> representing <xsl:copy-of select="$parent"/>.
	</SPAN>
	<H4>Usage <xsl:if test="count(@lang)"><SMALL>- <xsl:value-of select="@lang"/> Specific</SMALL></xsl:if></H4>
	<SAMP><xsl:copy-of select="$current"/></SAMP>
	<H4>Remarks</H4>
	<DIV>
		This macro is a shorthand form of the following <A href="{$root}/lambda.html">λ-binding</A>:
		<xsl:choose>
			<xsl:when test="ancestor::macro/@type = 'indirect' or ancestor::macro/@type = 'object'">
				<DIV class="PUSHPULL"><PRE><xsl:call-template name="manual"><xsl:with-param name="id" select="'LAMBDA'"/></xsl:call-template>(<xsl:call-template name="manual"><xsl:with-param name="id" select="concat(../@id, '_ID')"/></xsl:call-template>)()</PRE></DIV>
			</xsl:when>
			<xsl:otherwise>
				<DIV class="PUSHPULL"><PRE><xsl:call-template name="manual"><xsl:with-param name="id" select="'LAMBDA'"/></xsl:call-template>(<xsl:copy-of select="$parent"/>)</PRE></DIV>
			</xsl:otherwise>
		</xsl:choose>
	</DIV>
	<xsl:if test="count(listing)">
		<H4>Sample Code</H4>
		<xsl:for-each select="listing[1]">
			<SAMP><xsl:apply-templates/></SAMP>
		</xsl:for-each>
	</xsl:if>
</xsl:template>

<xsl:template match="derivative[substring-after(@id, ../@id) = '_BYPASS']">
	<xsl:variable name="current"><xsl:call-template name="manual"/></xsl:variable>
	<xsl:variable name="parent"><xsl:call-template name="manual-parent"/></xsl:variable>
	<HR/>
	<A name="{@id}"/>
	<H3 class="ALTERNATE">CHAOS_PP_<xsl:value-of select="@id"/></H3>
	<SPAN>
		The <xsl:copy-of select="$current"/> macro behaves identically to <xsl:copy-of select="$parent"/> except that it is parametized by the current <A href="{$root}/bypass.html">bypass recursion state</A>.
	</SPAN>
	<xsl:for-each select="usage">
		<xsl:variable name="position" select="position()"/>
		<H4>Usage <xsl:if test="count(@lang)"><SMALL>- <xsl:value-of select="@lang"/> Specific</SMALL></xsl:if></H4>
		<xsl:for-each select="syntax">
			<SAMP><xsl:apply-templates/></SAMP>
		</xsl:for-each>
		<DL>
			<DT><VAR>s</VAR></DT>
			<DD>The current <A href="{$root}/bypass.html">bypass recursion state</A>.</DD>
			<xsl:for-each select="ancestor::macro/usage[position() = $position]/param">
				<DT>
					<xsl:choose>
						<xsl:when test="@optional = '1'">[<VAR><xsl:value-of select="@id"/></VAR>]</xsl:when>
						<xsl:otherwise><VAR><xsl:value-of select="@id"/></VAR></xsl:otherwise>
					</xsl:choose>
				</DT>
				<DD><xsl:apply-templates/></DD>
			</xsl:for-each>
		</DL>
	</xsl:for-each>
	<H4>Remarks</H4>
	<DIV>
		If <A href="{$root}/bypass.html">bypass semantics</A> are already in effect, this macro must be used instead of <xsl:copy-of select="$parent"/>.
	</DIV>
	<xsl:if test="count(listing)">
		<H4>Sample Code</H4>
		<xsl:for-each select="listing[1]">
			<SAMP><xsl:apply-templates/></SAMP>
		</xsl:for-each>
	</xsl:if>
	<xsl:apply-templates select="derivative"/>
</xsl:template>

<xsl:template match="derivative[substring-after(@id, ../@id) = '_S']">
	<xsl:variable name="current"><xsl:call-template name="manual"/></xsl:variable>
	<xsl:variable name="parent"><xsl:call-template name="manual-parent"/></xsl:variable>
	<HR/>
	<A name="{@id}"/>
	<H3 class="ALTERNATE">CHAOS_PP_<xsl:value-of select="@id"/></H3>
	<SPAN>
		The <xsl:copy-of select="$current"/> macro behaves identically to <xsl:copy-of select="$parent"/> except that it is parametized by the <A href="{$root}/recursion.html">recursion state</A>.
	</SPAN>
	<xsl:for-each select="usage">
		<xsl:variable name="position" select="position()"/>
		<H4>Usage <xsl:if test="count(@lang)"><SMALL>- <xsl:value-of select="@lang"/> Specific</SMALL></xsl:if></H4>
		<xsl:for-each select="syntax">
			<SAMP><xsl:apply-templates/></SAMP>
		</xsl:for-each>
		<DL>
			<DT><VAR>s</VAR></DT>
			<DD>The current <A href="{$root}/recursion.html">recursion state</A>.</DD>
			<xsl:for-each select="ancestor::macro/usage[position() = $position]/param">
				<DT>
					<xsl:choose>
						<xsl:when test="@optional = '1'">[<VAR><xsl:value-of select="@id"/></VAR>]</xsl:when>
						<xsl:otherwise><VAR><xsl:value-of select="@id"/></VAR></xsl:otherwise>
					</xsl:choose>
				</DT>
				<DD><xsl:apply-templates/></DD>
			</xsl:for-each>
		</DL>
	</xsl:for-each>
	<H4>Remarks</H4>
	<DIV>
		This macro may not be used if <A href="{$root}/bypass.html">bypass semantics</A> are in effect.
	</DIV>
	<xsl:if test="count(listing)">
		<H4>Sample Code</H4>
		<xsl:for-each select="listing[1]">
			<SAMP><xsl:apply-templates/></SAMP>
		</xsl:for-each>
	</xsl:if>
	<xsl:apply-templates select="derivative"/>
</xsl:template>

</xsl:stylesheet>