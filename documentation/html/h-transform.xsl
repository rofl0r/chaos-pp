<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="html" doctype-public="-//W3C//DTD HTML 4.0 Strict//EN" indent="yes" encoding="UTF-8"/>

<xsl:include href="_lookup.xsl"/>
<xsl:include href="common.xsl"/>
<xsl:include href="whitespace.xsl"/>

<xsl:variable name="root" select="/header/@root"/>
<xsl:variable name="self" select="/header/@name"/>

<xsl:template match="self"><CODE><xsl:value-of select="$self"/></CODE></xsl:template>

<xsl:template match="code"><CODE><xsl:apply-templates/></CODE></xsl:template>
<xsl:template match="em"><EM><xsl:apply-templates/></EM></xsl:template>
<xsl:template match="var"><VAR><xsl:apply-templates/></VAR></xsl:template>

<xsl:template match="snippet"><DIV><PRE><xsl:apply-templates/></PRE></DIV></xsl:template>

<xsl:template match="*" priority="-1"><CODE><S>&lt;UNKNOWN-ENTITY&gt;</S></CODE></xsl:template>

<xsl:template name="manual">
	<xsl:param name="id"/>
	<xsl:for-each select="document('_lookup.xsl')/xsl:stylesheet/xsl:template[@match = translate($id, '/', '-')]//a[1]">
		<CODE><A href="{$root}/{substring-after(@href, '/')}"><xsl:apply-templates/></A></CODE>
	</xsl:for-each>
</xsl:template>

<xsl:template match="/">
	<HTML>
		<HEAD>
			<TITLE>&lt;chaos/preprocessor/<xsl:value-of select="$self"/>&gt;</TITLE>
			<LINK rel="stylesheet" type="text/css" href="{$root}/style.css"/>
		</HEAD>
		<BODY>
			<xsl:apply-templates select="header"/>
			<xsl:call-template name="copyright"/>
		</BODY>
	</HTML>
</xsl:template>

<xsl:template match="/header">
	<xsl:for-each select="abstract"><SPAN><xsl:apply-templates/></SPAN></xsl:for-each>
	<H4>Usage</H4>
	<SAMP>#include <xsl:call-template name="manual"><xsl:with-param name="id" select="$self"/></xsl:call-template></SAMP>
	<xsl:if test="count(macro)">
		<H4>Contents</H4>
		<UL>
			<xsl:for-each select="macro | .//derivative">
				<xsl:sort select="@id"/>
				<LI><CODE><A href="#{@id}">CHAOS_PP_<xsl:value-of select="@id"/></A></CODE></LI>
			</xsl:for-each>
		</UL>
	</xsl:if>
	<xsl:apply-templates select="macro"/>
</xsl:template>

<xsl:template match="/header/macro">
	<HR/>
	<A name="{@id}"/>
	<H3>CHAOS_PP_<xsl:value-of select="@id"/></H3>
	<xsl:for-each select="abstract"><SPAN><xsl:apply-templates/></SPAN></xsl:for-each>
	<xsl:for-each select="usage">
		<H4>Usage <xsl:if test="count(@lang)"><SMALL>- <xsl:value-of select="@lang"/> Specific</SMALL></xsl:if></H4>
		<xsl:for-each select="syntax"><SAMP><xsl:apply-templates/></SAMP></xsl:for-each>
		<xsl:if test="count(param)">
			<DL>
				<xsl:for-each select="param">
					<DT>
						<xsl:choose>
							<xsl:when test="@optional = '1'">[<VAR><xsl:value-of select="@id"/></VAR>]</xsl:when>
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
		<xsl:for-each select="para"><DIV><xsl:apply-templates/></DIV></xsl:for-each>
	</xsl:if>
	<xsl:if test="count(listing)">
		<H4>Sample Code</H4>
		<xsl:for-each select="listing"><SAMP><xsl:apply-templates/></SAMP></xsl:for-each>
	</xsl:if>
	<xsl:apply-templates select="derivative"/>
</xsl:template>

<xsl:template match="derivative[substring-after(@id, ../@id) = '_ID']">
	<HR/>
	<A name="{@id}"/>
	<H3>CHAOS_PP_<xsl:value-of select="@id"/></H3>
	<SPAN>
		The <xsl:call-template name="manual"><xsl:with-param name="id" select="@id"/></xsl:call-template> macro
		indirectly expands to <xsl:call-template name="manual"><xsl:with-param name="id" select="../@id"/></xsl:call-template>.
	</SPAN>
	<H4>Usage <xsl:if test="count(@lang)"><SMALL>- <xsl:value-of select="@lang"/> Specific</SMALL></xsl:if></H4>
	<SAMP><xsl:call-template name="manual"><xsl:with-param name="id" select="@id"/></xsl:call-template>()</SAMP>
	<H4>Remarks</H4>
	<DIV>
		<xsl:choose>
			<xsl:when test="ancestor::macro/@type = 'indirect'">
				This macro effectively allows <xsl:call-template name="manual"><xsl:with-param name="id" select="../@id"/></xsl:call-template>
				to pass through itself without becoming disabled.
			</xsl:when>
			<xsl:otherwise>
				This macro exists only for uniformity with other macros that require indirection invocation.
			</xsl:otherwise>
		</xsl:choose>
	</DIV>
	<xsl:if test="count(listing)">
		<H4>Sample Code</H4>
		<xsl:for-each select="listing"><SAMP><xsl:apply-templates/></SAMP></xsl:for-each>
	</xsl:if>
</xsl:template>

<xsl:template match="derivative[substring-after(@id, ../@id) = '_']">
	<HR/>
	<A name="{@id}"/>
	<H3>CHAOS_PP_<xsl:value-of select="@id"/></H3>
	<SPAN>
		The <xsl:call-template name="manual"><xsl:with-param name="id" select="@id"/></xsl:call-template> macro
		expands to a <A href="{$root}/lambda.html">lambda expression</A> representing <xsl:call-template name="manual"><xsl:with-param name="id" select="../@id"/></xsl:call-template>.
	</SPAN>
	<H4>Usage <xsl:if test="count(@lang)"><SMALL>- <xsl:value-of select="@lang"/> Specific</SMALL></xsl:if></H4>
	<SAMP><xsl:call-template name="manual"><xsl:with-param name="id" select="@id"/></xsl:call-template></SAMP>
	<H4>Remarks</H4>
	<DIV>
		This macro is a shorthand form of the following <A href="{$root}/lambda.html">lambda expression</A>:
		<xsl:choose>
			<xsl:when test="ancestor::macro/@type = 'indirect'">
				<DIV><PRE><xsl:call-template name="manual"><xsl:with-param name="id" select="'LAMBDA'"/></xsl:call-template>(<xsl:call-template name="manual"><xsl:with-param name="id" select="concat(../@id, '_ID')"/></xsl:call-template>)()</PRE></DIV>
			</xsl:when>
			<xsl:otherwise>
				<DIV><PRE><xsl:call-template name="manual"><xsl:with-param name="id" select="'LAMBDA'"/></xsl:call-template>(<xsl:call-template name="manual"><xsl:with-param name="id" select="../@id"/></xsl:call-template>)</PRE></DIV>
			</xsl:otherwise>
		</xsl:choose>
	</DIV>
	<xsl:if test="count(listing)">
		<H4>Sample Code</H4>
		<xsl:for-each select="listing"><SAMP><xsl:apply-templates/></SAMP></xsl:for-each>
	</xsl:if>
</xsl:template>

<xsl:template match="derivative[substring-after(@id, ../@id) = '_SHADOW']">
	<HR/>
	<A name="{@id}"/>
	<H3>CHAOS_PP_<xsl:value-of select="@id"/></H3>
	<SPAN>
		The <xsl:call-template name="manual"><xsl:with-param name="id" select="@id"/></xsl:call-template> macro
		is identical to <xsl:call-template name="manual"><xsl:with-param name="id" select="../@id"/></xsl:call-template>
		except that <A href="{$root}/active.html">active arguments</A> are restricted.
	</SPAN>
	<xsl:for-each select="usage">
		<xsl:variable name="lang" select="@lang"/>
		<H4>Usage <xsl:if test="count(@lang)"><SMALL>- <xsl:value-of select="@lang"/> Specific</SMALL></xsl:if></H4>
		<xsl:for-each select="syntax"><SAMP><xsl:apply-templates/></SAMP></xsl:for-each>
		<xsl:if test="count(ancestor::macro/usage[@lang = $lang or count($lang) = 0]/param)">
			<DL>
				<xsl:for-each select="ancestor::macro/usage[@lang = $lang or count($lang) = 0]/param">
					<DT>
						<xsl:choose>
							<xsl:when test="@optional = '1'">[<VAR><xsl:value-of select="@id"/></VAR>]</xsl:when>
							<xsl:otherwise><VAR><xsl:value-of select="@id"/></VAR></xsl:otherwise>
						</xsl:choose>
					</DT>
					<DD><xsl:apply-templates/></DD>
				</xsl:for-each>
			</DL>
		</xsl:if>
	</xsl:for-each>
	<H4>Remarks</H4>
	<DIV>
		This macro should be used only when its input is <A href="{$root}/active.html">inactive</A>.
		It exists to be used by <A href="{$root}/active.html">active arguments</A> specifically and to increase <A href="{$root}/containment.html">containment</A> in general.
	</DIV>
	<xsl:if test="count(listing)">
		<H4>Sample Code</H4>
		<xsl:for-each select="listing"><SAMP><xsl:apply-templates/></SAMP></xsl:for-each>
	</xsl:if>
</xsl:template>

<!-- _BYPASS -->

<!-- _S -->

<!-- _PARAMETRIC -->

<!-- _PARAMETRIC_S -->

</xsl:stylesheet>
