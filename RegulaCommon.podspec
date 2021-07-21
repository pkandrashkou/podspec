Pod::Spec.new do |s|
  s.name                = 'RegulaCommon'
  s.version             = '0.0.1'
  s.homepage              = 'https://regula.com'
  s.license              = { type: 'commercial', text: <<-LICENSE
    © 2020 RegulaForensics. All rights reserved.
  LICENSE
    }
  s.authors             = { 'RegulaForensics' => 'support@regulaforensics.com' }
  s.summary           = 'This is a private cocoapods wrapper intended only for INTERNAL usage!'
  s.platform             = :ios, '9.0'
  s.source              = { http: 'http://192.168.100.73:8000/regula-common/0.0.1.zip' }
  s.module_name         = 'RegulaCommon'
  s.vendored_frameworks = 'RegulaCommon.framework'
end
