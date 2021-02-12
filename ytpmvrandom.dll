if let audioURL1 = Bundle.main.url(forResource: Audio1, withExtension: Mp3Extension) {
  LoadingView.lockView()

  VideoGenerator.fileName = MultipleSingleMovieFileName
  VideoGenerator.shouldOptimiseImageForVideo = true

  VideoGenerator.current.generate(withImages: [#imageLiteral(resourceName: "image1"), #imageLiteral(resourceName: "image2"), #imageLiteral(resourceName: "image3"), #imageLiteral(resourceName: "image4")], andAudios: [audioURL1], andType: .singleAudioMultipleImage, { (progress) in
    print(progress)
  }, success: { (url) in
    LoadingView.unlockView()
    print(url)
    self.createAlertView(message: self.FnishedMultipleVideoGeneration)
  }, failure: { (error) in
    LoadingView.unlockView()
    print(error)
    self.createAlertView(message: error.localizedDescription)
  })
} else {
  self.createAlertView(message: MissingAudioFiles)
}

if let videoURL1 = Bundle.main.url(forResource: Video2, withExtension: MovExtension) {
  LoadingView.lockView()
  VideoGenerator.fileName = ReversedMovieFileName
  
  VideoGenerator.current.reverseVideo(fromVideo: videoURL1, success: { (videoURL) in
    LoadingView.unlockView()
    self.createAlertView(message: self.FinishReversingVideo)
    print(videoURL)
  }, failure: { (error) in
    LoadingView.unlockView()
    print(error)
    self.createAlertView(message: error.localizedDescription)
  })
} else {
  self.createAlertView(message: self.MissingVideoFiles)
}

if let videoURL1 = Bundle.main.url(forResource: Video1, withExtension: MOVExtension) {
  LoadingView.lockView()

  VideoGenerator.fileName = SplitMovieFileName
  
  VideoGenerator.current.splitVideo(withURL: videoURL1, atStartTime: 10, andEndTime: 40, success: { (url) in
    LoadingView.unlockView()
    print(url)
    self.createAlertView(message: self.FinishSplittingVideo)
  }, failure: { (error) in
    LoadingView.unlockView()
    print(error)
    self.createAlertView(message: error.localizedDescription)
  })
} else {
  self.createAlertView(message: self.MissingVideoFiles)
}

