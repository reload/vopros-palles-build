; Make file for building Biblioteksvagten Vopros installation.

api = 2
core = 7.x

projects[drupal] = drupal
projects[drupal][version] = 7.26

projects[vopros][type] = "profile"
projects[vopros][download][type] = "git"
projects[vopros][download][url] = "https://github.com/DBCDK/Vopros-install.git"


; Palles Gavebod specific additions.

projects[wysiwyg][version] = 2.2
; Custom libraries.

libraries[ckeditor][download][type] = get
libraries[ckeditor][download][url] = http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.1/ckeditor_3.6.1.tar.gz
libraries[ckeditor][directory_name] = ckeditor
libraries[ckeditor][destination] = libraries

