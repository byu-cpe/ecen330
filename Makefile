install:
	bundle install

build: install
	bundle exec jekyll build

serve: install
	bundle exec jekyll serve --livereload

check_links: build
	bundle exec htmlproofer --swap-urls "^\/ecen330:" --allow_missing_href=true --ignore-status-codes "0,200,301,403" ./_site

deploy:
	bundle exec jekyll build
	ssh byu-domains "rm -rf public_html/courses/ecen625/*"
	scp -r _site/* byu-domains:public_html/courses/ecen625/
