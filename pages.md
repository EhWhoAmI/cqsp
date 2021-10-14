# Pages

<ul>
  {% for post in site.posts limit:10 %}
    <li>
      {{ page.date | date: '%B %d, %Y' }}: <a href="{{ post.url }}">{{ post.title }}</a>
    </li>
  {% endfor %}
</ul>
