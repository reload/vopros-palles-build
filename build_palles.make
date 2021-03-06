; Make file for building Biblioteksvagten Vopros installation.

api = 2
core = 7.x

projects[drupal] = drupal
projects[drupal][version] = 7.41

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

libraries[ckeditor][download][type] = file
libraries[ckeditor][download][url] = https://raw.githubusercontent.com/reload/vopros-palles-build/master/palles_vopros.drush.inc
libraries[ckeditor][directory_name] = palles_vopros
libraries[ckeditor][destination] = drush

