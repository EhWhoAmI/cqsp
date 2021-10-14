# Pages

<ul>
  {% for post in site.posts %}
    <li>
      {{ post.date | date: '%B %d, %Y' }}: <a href="{{ post.url }}">{{ post.title }}</a>
      {% if page.excerpt and page.excerpt != "" %}
        - {{ page.excerpt }}
      {% endif %}
    </li>
  {% endfor %}
</ul>
