<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="html" indent="yes" encoding="UTF-8"/>
<xsl:include href="_lookup.xsl"/>

<xsl:variable name="root" select="/header/@root"/>
<xsl:variable name="self" select="/header/@name"/>

<xsl:template match="self"><code><xsl:value-of select="$self"/></code></xsl:template>

<xsl:template match="em"><em><xsl:apply-templates/></em></xsl:template>
<xsl:template match="var"><var><xsl:apply-templates/></var></xsl:template>
<xsl:template match="code"><code><xsl:apply-templates/></code></xsl:template>

<!-- TOPICS -->
<xsl:template match="lambda"><a class="topic" href="{@root}/topics/lambda.html"><xsl:value-of select="@text"/></a></xsl:template>
<xsl:template match="recursion"><a class="topic" href="{@root}/topics/recursion.html"><xsl:value-of select="@text"/></a></xsl:template>

<!-- COPYRIGHT/LICENSE -->
<xsl:template name="copyright">
	<hr/>
	<address>© Copyright Paul Mensonides 2003</address>
</xsl:template>

<!-- MANUAL SYMBOL LOOKUP -->
<xsl:template name="lookup"><xsl:param name="id"/>
	<xsl:for-each select="document('_lookup.xsl')/xsl:stylesheet/xsl:template[@match = translate($id, '/', '-')]/a[1]"><a class="{@class}" href="{$root}/{substring-after(@href, '/')}"><xsl:apply-templates/></a></xsl:for-each>
</xsl:template>

<!-- DOCUMENT-RELATED STRUCTURE -->
<xsl:template match="/">
	<html>
		<head>
			<title>&lt;chaos/preprocessor/<xsl:value-of select="$self"/>&gt;</title>
			<link rel="stylesheet" type="text/css" href="{$root}/style.css"/>
		</head>
		<body>
			<xsl:apply-templates select="header"/>
			<xsl:call-template name="copyright"/>
		</body>
	</html>
</xsl:template>

<!-- HEADER-RELATED STRUCTURE -->
<xsl:template match="/header">
	<xsl:apply-templates select="synopsis"/>
	<h4>Usage</h4>
	<div class="code">
		#include <xsl:call-template name="lookup"><xsl:with-param name="id" select="$self"/></xsl:call-template>
	</div>
	<xsl:if test="symbol">
		<h4>Contents</h4>
		<ul>
			<xsl:for-each select="symbol | .//derivative">
				<xsl:sort select="@id"/>
				<li><a href="#{@id}"><code>CHAOS_PP_<xsl:value-of select="@id"/></code></a></li>
			</xsl:for-each>
		</ul>
	</xsl:if>
	<xsl:apply-templates select="symbol"/>
</xsl:template>

<!-- SYMBOL-RELATED STRUCTURE -->
<xsl:template match="/header/symbol">
	<hr/>
	<a name="{@id}"/>
	<h3>CHAOS_PP_<xsl:value-of select="@id"/></h3>
	<xsl:apply-templates select="abstract"/>
	<xsl:for-each select="usage">
		<h4>Usage <xsl:if test="@lang"><s class="lang">(<xsl:value-of select="@lang"/> Specific)</s></xsl:if></h4>
		<xsl:apply-templates select="syntax"/>
		<xsl:if test="param">
			<dl>
				<xsl:for-each select="param">
					<dt>
						<xsl:choose>
							<xsl:when test="@optional = 'true'">[<xsl:value-of select="@id"/>]</xsl:when>
							<xsl:otherwise><xsl:value-of select="@id"/></xsl:otherwise>
						</xsl:choose>
					</dt>
					<dd><xsl:apply-templates/></dd>
				</xsl:for-each>
			</dl>
		</xsl:if>
	</xsl:for-each>
	<xsl:if test="para">
		<h4>Remarks</h4>
		<xsl:for-each select="para"><div><xsl:apply-templates/></div></xsl:for-each>
	</xsl:if>
	<xsl:if test="listing">
		<h4>Sample Code</h4>
		<xsl:for-each select="listing"><div class="code"><pre><xsl:apply-templates/></pre></div></xsl:for-each>
	</xsl:if>
	<xsl:apply-templates select="derivative"/>
</xsl:template>

<xsl:template match="synopsis | abstract">
	<div class="synopsis"><xsl:apply-templates/></div>
</xsl:template>

<xsl:template match="syntax">
	<div class="code"><xsl:apply-templates/></div>
</xsl:template>

<!-- INLINE CODE SNIPPET -->
<xsl:template match="snippet"><div><pre><xsl:apply-templates/></pre></div></xsl:template>

<!-- UNKNOWN ENTITY -->
<xsl:template match="*" priority="-1"><s class="unknown"><code>UNDEFINED</code></s></xsl:template>

<!-- DERIVATIVE SYMBOLS -->

<xsl:template match="derivative[substring-after(@id, ../@id) = '_ID']">
	<hr/>
	<a name="{@id}"/>
	<h3>CHAOS_PP_<xsl:value-of select="@id"/></h3>
	<div class="synopsis">
		The <xsl:call-template name="lookup"><xsl:with-param name="id" select="@id"/></xsl:call-template> macro
		indirectly expands to <xsl:call-template name="lookup"><xsl:with-param name="id" select="../@id"/></xsl:call-template>.
	</div>
	<h4>Usage <xsl:if test="@lang"><s class="lang">(<xsl:value-of select="@lang"/> Specific)</s></xsl:if></h4>
	<div class="code">
		<xsl:call-template name="lookup"><xsl:with-param name="id" select="@id"/></xsl:call-template>()
	</div>
	<h4>Remarks</h4>
	<div>
		<xsl:choose>
			<xsl:when test="@buffer = 'false'">
				This macro exists only for uniformity with other macros that require indirect invocation.
			</xsl:when>
			<xsl:otherwise>
				This macro effectively allows <xsl:call-template name="lookup"><xsl:with-param name="id" select="../@id"/></xsl:call-template>
				to pass through itself without becoming disabled.
			</xsl:otherwise>
		</xsl:choose>
	</div>
</xsl:template>

<xsl:template match="derivative[substring-after(@id, ../@id) = '_']">
	<hr/>
	<a name="{@id}"/>
	<h3>CHAOS_PP_<xsl:value-of select="@id"/></h3>
	<div class="synopsis">
		The <xsl:call-template name="lookup"><xsl:with-param name="id" select="@id"/></xsl:call-template> macro
		expands to a <a class="topic" href="{$root}/topics/lambda.html">restricted lambda expression</a> representing
		<xsl:call-template name="lookup"><xsl:with-param name="id" select="../@id"/></xsl:call-template>.
	</div>
	<h4>Usage <s class="lang">(C99 Specific)</s></h4>
	<div class="code"><xsl:call-template name="lookup"><xsl:with-param name="id" select="@id"/></xsl:call-template></div>
	<h4>Remarks</h4>
	<div>
		This macro is a shorthand form of the following <a class="topic" href="{$root}/topics/lambda.html">lambda expression</a>:
		<xsl:choose>
			<xsl:when test="@buffer = 'false'">
				<div><pre><xsl:call-template name="lookup"><xsl:with-param name="id" select="'LAMBDA'"/></xsl:call-template>(<xsl:call-template name="lookup"><xsl:with-param name="id" select="../@id"/></xsl:call-template>)</pre></div>
			</xsl:when>
			<xsl:otherwise>
				<div><pre><xsl:call-template name="lookup"><xsl:with-param name="id" select="'LAMBDA'"/></xsl:call-template>(<xsl:call-template name="lookup"><xsl:with-param name="id" select="concat(../@id, '_ID')"/></xsl:call-template>)()</pre></div>
			</xsl:otherwise>
		</xsl:choose>
	</div>
</xsl:template>

</xsl:stylesheet>
