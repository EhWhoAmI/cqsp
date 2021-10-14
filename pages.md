# Pages

<ul>
  {% for post in site.posts %}
    <li>
      {{ post.date | date: '%B %d, %Y' }}: <a href="{{ post.url }}">{{ post.title }}</a> - {{ page.excerpt }}
    </li>
  {% endfor %}
</ul>
