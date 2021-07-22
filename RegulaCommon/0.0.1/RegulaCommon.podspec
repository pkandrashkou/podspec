Pod::Spec.new do |s|
  s.name                = 'RegulaCommon'
  s.version             = '0.0.1'
  s.homepage = 'https://regula.com'
  s.license = { type: 'commercial', text: <<-LICENSE
    © 2020 RegulaForensics. All rights reserved.
  LICENSE
    }
  s.authors = { 'RegulaForensics' => 'support@regulaforensics.com' }
  s.summary              = 'This is a private cocoapods wrapper intended only for INTERNAL usage!'
  s.platform             = :ios, '9.0'
  s.source              = { http: 'http://ftp.regula.local/iOS/RegulaCommon/regula-common/0.0.1.zip' }
  s.module_name         = 'RegulaCommon'

  s.default_subspec     = 'Core'
  s.subspec 'Core' do |core|
    core.preserve_paths      = 'RegulaCommon.framework'
    core.vendored_frameworks = 'RegulaCommon.framework'
  end
end
