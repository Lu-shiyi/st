## HEADER
This is an H1
=============
This is an H2
-------------

-----------------------------------------------------------------------------
## QUOTE
> This is the first level of quoting.
>
> > This is nested blockquote.
>
> Back to the first level.

> ## This is a header.
> 
> 1.   This is the first list item.
> 2.   This is the second list item.
> 
> Here's some example code:
> 
>     return shell_exec("echo $input | $markdown_script");

----------------------------------------------------------------------------
## CODE
```python
print('hello,world')
```

```js
console.log('hello,world')
```

```cpp
cout<<"hello,world"<<endl;
```

This is a normal paragraph:

    This is a code block.

<p>This is a normal paragraph:</p>
<pre><code>This is a code block.
</code></pre>

<p>Here is an example of AppleScript:</p>

<pre><code>tell application "Foo"
    beep
end tell
</code></pre>

    <div class="footer">
        &copy; 2021 Foo Corporation
    </div>

<div class="footer">
    &copy; 2021 Foo Corporation
</div>

Use the `printf()` function.

<p>Use the <code>printf()</code> function.</p>

``There is a literal backtick (`) here.``

<p><code>There is a literal backtick (`) here.</code></p>

A single backtick in a code span: `` ` ``

A backtick-delimited string in a code span: `` `foo` ``

Please don't use any `<blink>` tags.

<p>Please don't use any <code>&lt;blink&gt;</code> tags.</p>

`&#8212;` is the decimal-encoded equivalent of `&mdash;`.

<p><code>&amp;#8212;</code> is the decimal-encoded
equivalent of <code>&amp;mdash;</code>.</p>

----------------------------------------------------------------------------
## LIST
<ol>
<li>Bird</li>
<li>McHale</li>
<li>Parish</li>
</ol>

1. Bird
2. McHale
3. Parish

<ul>
<li>M4</li>
<li>AK</li>
</ul>
   
+ M4
+ AK

*   Bird
  
*   Magic

<ul>
<li><p>Bird</p></li>
<li><p>Magic</p></li>
</ul>

----------------------------------------------------------------------------
## LINK
This is [an example](http://example.com/ "Title") inline link.

[This link](http://example.net/) has no title attribute.

<p>This is <a href="http://example.com/" title="Title">an example</a> inline link.</p>

<p><a href="http://example.net/">This link</a> has no
title attribute.</p>

See [README](/README.md) for details

This is [an example][id] reference-style link.

[id]: http://example.com/  "Optional Title Here"

[Google][]

[Google]:http://google.com/

I get 10 times more traffic from [Google][1] than from[Yahoo][2] or [MSN][3].

[1]: http://google.com/        "Google"
[2]: http://search.yahoo.com/  "Yahoo Search"
[3]: http://search.msn.com/    "MSN Search"

<p>I get 10 times more traffic from <a href="http://google.com/"
title="Google">Google</a> than from
<a href="http://search.yahoo.com/" title="Yahoo Search">Yahoo</a>
or <a href="http://search.msn.com/" title="MSN Search">MSN</a>.</p>

----------------------------------------------------------------------------
## PICTURE
![test image size](me.jpg)
![text][me]

<img src="me.jpg" alt="text" width=100 height=100>

[me]: me.jpg

----------------------------------------------------------------------------
## TIPS
1. 4
   
1\. 4

5<6  
5&lt;6

1&0  
1&amp;0

列1 | 列2 | 列3
-: | :-: | :-
单元格1 | 单元格2 | 单元格3
1|2|3
4|5|6

<p>use<kbd>CTRL</kbd>+<kbd>SHIFT</kbd>+<kbd>ESC</kbd>to call task manager</p>

*single asterisks*

_single underscores_

**double asterisks**

__double underscores__

<em>single asterisks</em>

<em>single underscores</em>

<strong>double asterisks</strong>

<strong>double underscores</strong>

TEXT   
**TEXT**   
*TEXT*   
***TEXT***


copyright&copy;2021 All rights reserved.